from codecs import latin_1_decode
import numpy as np


class SolarPosition:
    # AUTHOR:
    #	Zachary Steenson
    #		
    # DATE:
    #	October 18, 2022
    #
    # DESCRIPTION:
    # 	Computes Solar Position factors, given the date, time, and
    #	location of a site.  The passed parameters are defined below.
    #	Based on:
    #
    #	Michalsky, Joseph J. (1988).  The Astronomical Almanac's 
    #		algorithm for approximate solar position (1950-2050).
    #		Solar Energy 40 (3); 227-235.
    #
    # INPUTS:
    #	--DATE--
    #		year:	Year, e.g., 1990
    #		month:	Month of year, 1-12, e.g., 4=April
    #		day:	Day of month, 1-31
    #	--TIME--
    #		hour:	Hour of day, 0-23
    #		minute:	Minute of hour, 0-59      
    #		second:	Second of minute, 0-59
    #
    #	x_lat:	Latitude in decimal degrees, N +
    #	x_lon:	Longitude in decimal degrees, E +
    #	time_zone:	Time zone number:  Pacific = -8, Mountain = -7,
    #				   Central = -6, Eastern = -5
    #
    # OUTPUTS:
    #	sol_zen:	Solar zenith angle (angle sun makes with zenith), 
    #		  degrees.
    #	sol_azm:	Solar azimuth angle, degrees, 0 = N, 90 = E.
    #	ETR:	Extraterrestrial global horizontal solar radiation;
    #		  what Global would read in space.
    #	ETRN:	ETR Normal, what Direct would read in space.
    #	air_mass:	Relative optical airmass (the thickness of the 
    #		  atmosphere) normalized to 1 standard atmosphere 
    #		  (sea-level, looking straight up).
    #
    # ======================================================================#
    
    def __init__(self, year: int, month: int, day: int, hour: int, minute: int, 
                    second: int, x_lat: float, x_long: float, time_zone: int) -> None:
        self.year = year
        self.month = month
        self.day = day
        self.hour = hour
        self.minute = minute
        self.second = second
        self.x_lat = x_lat
        self.x_long = x_long
        self.time_zone = time_zone
        self.SUNAZ = 0
        self.SUNEL = 0
        self.universal_time = 0
        
        self.dr: int = 0.017453292
        
        self.define_all_parameters()
    
    def get_universal_time(self) -> None:
        
        self.universal_time: float = (int(self.hour) * 3600) + (int(self.minute) * 60) + int(self.second)
        self.universal_time = (self.universal_time / 3600.0) - self.time_zone
        
    def get_num_days_in_year(self) -> int:
        
        m_days: int = 0
        match self.month:
            case 1: m_days = 0
            case 2: m_days = 31
            case 3: m_days = 59
            case 4: m_days = 90
            case 5: m_days = 120
            case 6: m_days = 151
            case 7: m_days = 181
            case 8: m_days = 212
            case 9: m_days = 243
            case 10: m_days = 273
            case 11: m_days = 304
            case 12: m_days = 334
        
        num_days: int = m_days + self.day
        
        # Account for Leap years in February
        if (self.year % 4 == 0 and self.month == 2):
            num_days += 1
        
        return num_days
    
    def define_all_parameters(self) -> None:
        
        self.get_universal_time()
        num_days: int = self.get_num_days_in_year()
        
        # Day angle (Jan 1 = 0 deg, goes to 360)
        d_angle = (360.0 * (num_days - 1)) / 365.0
        
        # Fix for leap year, and adjust for 1949 = day 0
        if (self.year < 100): 
            self.year += 1900
            
        delta: int = self.year - 1949
        x_leap: int = delta / 4
        
        # Julian Day Starts in 1949
        day_jul = (32916.5 + (delta * 365.0)  + x_leap + 
                    num_days + (self.universal_time / 24.0))
        
        if (self.year % 100 == 0 and self.year % 400 == 0):
            day_jul -= 1.0
        
        # GMST is the Greenwich Mean Sidereal Time (in hours)
        
        ep_time = day_jul - 51545.0
        
        GMST = 6.697375 + 0.0657098242 * ep_time + self.universal_time
        
        GMST %= 24.0
        
        # XLMST is the Local Mean Sidereal Time:
        
        XLMST = (GMST * 15.0) + self.x_long
        XLMST %= 360.0
        if (XLMST < 0):
            XLMST += 360.0
            
        # OBLECl is the Obliquity of the Ecliptic
        
        obl_ecl = 23.439 + (4e-7 * ep_time)
        
        #  XMANOM is the Mean Anomaly
        
        xm_anom = 357.528 + (0.9856003 * ep_time)
        xm_anom %= 360.0
        if (xm_anom < 0):
            xm_anom += 360.0
            
        # xm_long is the mean longitude
        xm_long = 357.528 + (0.9856474 * ep_time)
        xm_long %= 360.0
        if (xm_long < 0):
            xm_long += 360.0
            
        # Eclong is the longitude of the ecliptic
        ec_long = (xm_long + (1.915 * np.sin(xm_anom * self.dr))
                    + 0.020 * np.sin(2.0 * xm_anom * self.dr))
        
        ec_long %= 360.0
        if (ec_long < 0):
            ec_long += 360.0
            
        # Rascen is the right ascension (of the sun)
        top = np.cos(obl_ecl * self.dr) * np.sin(ec_long * self.dr)
        bottom = np.cos(ec_long * self.dr)
        ra_scen = np.arctan2(top, bottom) / self.dr
        if (ra_scen < 0.0):
            ra_scen += 360.0
            
        # hangle is the hour angle (hours)
        hangle =  XLMST - ra_scen
        if (hangle < -180.0):
            hangle += 360.0
        elif (hangle > 180.0):
            hangle -= 360.0
        
        # declin is the declination
        
        declin = np.arcsin(np.sin(obl_ecl*self.dr) * np.sin(ec_long*self.dr)) / self.dr
        
        D1 = d_angle
        D2 = 2 * D1
        S1 = np.sin(D1 * self.dr)
        S2 = np.sin(D2 * self.dr)
        C1 = np.cos(D1 * self.dr)
        C2 = np.cos(D2 * self.dr)
        
        # ERV is the Earth-sun Radius Vector (corrects distance from sun):
        
        ERV = 1.000110 + (0.034221*C1) + (0.001280*S1) + (0.000719*C2) + (0.000077*S2)
        
        Ch = np.cos(hangle * self.dr)
        Cl = np.cos(self.x_lat * self.dr)
        Cd = np.cos(declin * self.dr)
        Sl = np.sin(self.x_lat * self.dr)
        Sd = np.sin(declin * self.dr)
        
        Cz = Sd * Sl * Cd * Cl * Ch
        if (Cz > 1):
            Cz = 1.0
        elif (Cz < -1):
            Cz = -1.0
        
        # ETRzen is the solar zenith angle outside the atmosphere
        
        ETRzen = np.arccos(Cz) / self.dr
        ETRzen = min(ETRzen, 99.0)
        
        Ca = np.sin(ETRzen * self.dr)
        Sa = np.cos(ETRzen * self.dr)
        
        E = 90.0 - ETRzen
        
        # Refraction Correction
        
        refcor = 0.0
        if (E <= 85.0):
            Te = np.tan(E * self.dr)
            
            if (E >= 5.0):
                refcor = (58.1 / Te) - (0.07 / Te**3) + (.000086 / Te**5)
            elif (E >= -0.575):
                refcor = 1735.0 + (E * (-518.2 + (E * (103.4 + E * (-12.79 + E * 0.711)))))
            else:
                refcor = -20.774 / Te
            refcor /= 3600.0
        
        solelv = E + refcor
        solelv = max(solelv, -9.0)
        
        solzen = 90.0 - solelv
        
        # solazm is the solar asimuth angle:
        
        solazm = 180.0
        Al = Ca * Cl
        
        if (abs(Al) > 0.001):
            Caz = ((Sa * Sl) - Sd) / Al
            if (abs(Caz) > 1):
                Caz = 1.0 * np.sign(Caz)
            solazm = 180.0 - (np.arccos(Caz) / self.dr)
            if (hangle > 0):
                solazm = 360.0 - solazm
            
        # Solar Constant
        
        solcon = 1367.0
        
        # ETR is the extra-terrestrial horizontal solar radiation, and
        # ETRN is the extra-terrestrial direct normal solar radiaation:
        
        ETRN = solcon * ERV
        ETR = ETRN * np.cos(solzen * self.dr)
        if (ETR < 0):
            ETR = 0.0
            ETRN = 0.0
        
        # AMASS is the relative optical airmass (how much air is between us
        # and the sun:
        
        amass = -1.0
        if (ETRzen < 93.0):
            Cz = np.cos(ETRzen * self.dr)
            amass = 1.0 / (Cz + 0.50572 * ((96.07995 - ETRzen)**-1.6364))
            
        # Rename az/el parameters
        self.SUNAZ = solazm
        self.SUNEL = solelv
        
        