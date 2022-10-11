



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
    
        def __init__(self, year: int, month: int, day: int, hour: int, minute: int, second: int, time_zone: int) -> None:
            self.year = year
            self.month = month
            self.day = day
            self.hour = hour
            self.minute = minute
            self.second = second
            self.time_zone = time_zone
            
            self.dr: int = 0.017453292
        
        def get_universal_time(self) -> None:
            
            self.universal_time: float = (self.hour * 3600) + (self.minute * 60) + self.second
            self.universal_time = (self.universal_time / 3600.0) - self.time_zone
            
        def get_num_days