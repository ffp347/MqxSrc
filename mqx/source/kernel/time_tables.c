/*HEADER*********************************************************************
* 
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
* Copyright (c) 1989-2008 ARC International;
* All Rights Reserved
*
*************************************************************************** 
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR 
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: time_tables.c$
* $Version : 3.8.1.0$
* $Date    : Apr-13-2012$
*
* Comments:
*
*   This file contains the function for adding days to a tick
*   struct
*
*END************************************************************************/

#include "mqx_inc.h"


const uchar _time_days_in_month_internal[2][13] =
{
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

const uint_32 _time_secs_before_month_internal[2][13] =
{
   {
      0,
      31UL*SECS_IN_DAY,
      59UL*SECS_IN_DAY,
      90UL*SECS_IN_DAY,
      120UL*SECS_IN_DAY,
      151UL*SECS_IN_DAY,
      181UL*SECS_IN_DAY,
      212UL*SECS_IN_DAY,
      243UL*SECS_IN_DAY,
      273UL*SECS_IN_DAY,
      304UL*SECS_IN_DAY,
      334UL*SECS_IN_DAY,
      ~0
   },
   {
      0,
      31UL*SECS_IN_DAY,
      60UL*SECS_IN_DAY,
      91UL*SECS_IN_DAY,
      121UL*SECS_IN_DAY,
      152UL*SECS_IN_DAY,
      182UL*SECS_IN_DAY,
      213UL*SECS_IN_DAY,
      244UL*SECS_IN_DAY,
      274UL*SECS_IN_DAY,
      305UL*SECS_IN_DAY,
      335UL*SECS_IN_DAY,
      ~0
   }
};

/*
 * The following array contains the number of seconds between Jan 1, 1970
 * and a given year. For example, to determine the number of seconds 
 * between Jan 1, 1970 and Jan 1, 1988, the subscript (1988-1970) would
 * be used to index into this table. Note that the first entry is equal to 
 * zero (0).
 *
 * NOTE:  If this table is expanded to include the year 2100, then it must
 * be noted that the year 2100 is NOT a leap year.  Only century years 
 * divisible by 400 are leap years.
 */

const uint_32 _time_secs_before_year_internal[] =
{
   ((1970UL-1970UL) * SECS_IN_YEAR) + ( 0UL * SECS_IN_DAY),
   ((1971UL-1970UL) * SECS_IN_YEAR) + ( 0UL * SECS_IN_DAY),
   ((1972UL-1970UL) * SECS_IN_YEAR) + ( 0UL * SECS_IN_DAY),
   ((1973UL-1970UL) * SECS_IN_YEAR) + ( 1UL * SECS_IN_DAY),
   ((1974UL-1970UL) * SECS_IN_YEAR) + ( 1UL * SECS_IN_DAY),
   ((1975UL-1970UL) * SECS_IN_YEAR) + ( 1UL * SECS_IN_DAY),
   ((1976UL-1970UL) * SECS_IN_YEAR) + ( 1UL * SECS_IN_DAY),
   ((1977UL-1970UL) * SECS_IN_YEAR) + ( 2UL * SECS_IN_DAY),
   ((1978UL-1970UL) * SECS_IN_YEAR) + ( 2UL * SECS_IN_DAY),
   ((1979UL-1970UL) * SECS_IN_YEAR) + ( 2UL * SECS_IN_DAY),
   ((1980UL-1970UL) * SECS_IN_YEAR) + ( 2UL * SECS_IN_DAY),
   ((1981UL-1970UL) * SECS_IN_YEAR) + ( 3UL * SECS_IN_DAY),
   ((1982UL-1970UL) * SECS_IN_YEAR) + ( 3UL * SECS_IN_DAY),
   ((1983UL-1970UL) * SECS_IN_YEAR) + ( 3UL * SECS_IN_DAY),
   ((1984UL-1970UL) * SECS_IN_YEAR) + ( 3UL * SECS_IN_DAY),
   ((1985UL-1970UL) * SECS_IN_YEAR) + ( 4UL * SECS_IN_DAY),
   ((1986UL-1970UL) * SECS_IN_YEAR) + ( 4UL * SECS_IN_DAY),
   ((1987UL-1970UL) * SECS_IN_YEAR) + ( 4UL * SECS_IN_DAY),
   ((1988UL-1970UL) * SECS_IN_YEAR) + ( 4UL * SECS_IN_DAY),
   ((1989UL-1970UL) * SECS_IN_YEAR) + ( 5UL * SECS_IN_DAY),
   ((1990UL-1970UL) * SECS_IN_YEAR) + ( 5UL * SECS_IN_DAY),
   ((1991UL-1970UL) * SECS_IN_YEAR) + ( 5UL * SECS_IN_DAY),
   ((1992UL-1970UL) * SECS_IN_YEAR) + ( 5UL * SECS_IN_DAY),
   ((1993UL-1970UL) * SECS_IN_YEAR) + ( 6UL * SECS_IN_DAY),
   ((1994UL-1970UL) * SECS_IN_YEAR) + ( 6UL * SECS_IN_DAY),
   ((1996UL-1970UL) * SECS_IN_YEAR) + ( 6UL * SECS_IN_DAY),
   ((1996UL-1970UL) * SECS_IN_YEAR) + ( 6UL * SECS_IN_DAY),
   ((1997UL-1970UL) * SECS_IN_YEAR) + ( 7UL * SECS_IN_DAY),
   ((1998UL-1970UL) * SECS_IN_YEAR) + ( 7UL * SECS_IN_DAY),
   ((1999UL-1970UL) * SECS_IN_YEAR) + ( 7UL * SECS_IN_DAY),
   ((2000UL-1970UL) * SECS_IN_YEAR) + ( 7UL * SECS_IN_DAY),
   ((2001UL-1970UL) * SECS_IN_YEAR) + ( 8UL * SECS_IN_DAY),
   ((2002UL-1970UL) * SECS_IN_YEAR) + ( 8UL * SECS_IN_DAY),
   ((2003UL-1970UL) * SECS_IN_YEAR) + ( 8UL * SECS_IN_DAY),
   ((2004UL-1970UL) * SECS_IN_YEAR) + ( 8UL * SECS_IN_DAY),
   ((2005UL-1970UL) * SECS_IN_YEAR) + ( 9UL * SECS_IN_DAY),
   ((2006UL-1970UL) * SECS_IN_YEAR) + ( 9UL * SECS_IN_DAY),
   ((2007UL-1970UL) * SECS_IN_YEAR) + ( 9UL * SECS_IN_DAY),
   ((2008UL-1970UL) * SECS_IN_YEAR) + ( 9UL * SECS_IN_DAY),
   ((2009UL-1970UL) * SECS_IN_YEAR) + (10UL * SECS_IN_DAY),
   ((2010UL-1970UL) * SECS_IN_YEAR) + (10UL * SECS_IN_DAY),
   ((2011UL-1970UL) * SECS_IN_YEAR) + (10UL * SECS_IN_DAY),
   ((2012UL-1970UL) * SECS_IN_YEAR) + (10UL * SECS_IN_DAY),
   ((2013UL-1970UL) * SECS_IN_YEAR) + (11UL * SECS_IN_DAY),
   ((2014UL-1970UL) * SECS_IN_YEAR) + (11UL * SECS_IN_DAY),
   ((2015UL-1970UL) * SECS_IN_YEAR) + (11UL * SECS_IN_DAY),
   ((2016UL-1970UL) * SECS_IN_YEAR) + (11UL * SECS_IN_DAY),
   ((2017UL-1970UL) * SECS_IN_YEAR) + (12UL * SECS_IN_DAY),
   ((2018UL-1970UL) * SECS_IN_YEAR) + (12UL * SECS_IN_DAY),
   ((2019UL-1970UL) * SECS_IN_YEAR) + (12UL * SECS_IN_DAY),
   ((2020UL-1970UL) * SECS_IN_YEAR) + (12UL * SECS_IN_DAY),
   ((2021UL-1970UL) * SECS_IN_YEAR) + (13UL * SECS_IN_DAY),
   ((2022UL-1970UL) * SECS_IN_YEAR) + (13UL * SECS_IN_DAY),
   ((2023UL-1970UL) * SECS_IN_YEAR) + (13UL * SECS_IN_DAY),
   ((2024UL-1970UL) * SECS_IN_YEAR) + (13UL * SECS_IN_DAY),
   ((2025UL-1970UL) * SECS_IN_YEAR) + (14UL * SECS_IN_DAY),
   ((2026UL-1970UL) * SECS_IN_YEAR) + (14UL * SECS_IN_DAY),
   ((2027UL-1970UL) * SECS_IN_YEAR) + (14UL * SECS_IN_DAY),
   ((2028UL-1970UL) * SECS_IN_YEAR) + (14UL * SECS_IN_DAY),
   ((2029UL-1970UL) * SECS_IN_YEAR) + (15UL * SECS_IN_DAY),
   ((2030UL-1970UL) * SECS_IN_YEAR) + (15UL * SECS_IN_DAY),
   ((2031UL-1970UL) * SECS_IN_YEAR) + (15UL * SECS_IN_DAY),
   ((2032UL-1970UL) * SECS_IN_YEAR) + (15UL * SECS_IN_DAY),
   ((2033UL-1970UL) * SECS_IN_YEAR) + (16UL * SECS_IN_DAY),
   ((2034UL-1970UL) * SECS_IN_YEAR) + (16UL * SECS_IN_DAY),
   ((2035UL-1970UL) * SECS_IN_YEAR) + (16UL * SECS_IN_DAY),
   ((2036UL-1970UL) * SECS_IN_YEAR) + (16UL * SECS_IN_DAY),
   ((2037UL-1970UL) * SECS_IN_YEAR) + (17UL * SECS_IN_DAY),
   ((2038UL-1970UL) * SECS_IN_YEAR) + (17UL * SECS_IN_DAY),
   ((2039UL-1970UL) * SECS_IN_YEAR) + (17UL * SECS_IN_DAY),
   ((2040UL-1970UL) * SECS_IN_YEAR) + (17UL * SECS_IN_DAY),
   ((2041UL-1970UL) * SECS_IN_YEAR) + (18UL * SECS_IN_DAY),
   ((2042UL-1970UL) * SECS_IN_YEAR) + (18UL * SECS_IN_DAY),
   ((2043UL-1970UL) * SECS_IN_YEAR) + (18UL * SECS_IN_DAY),
   ((2044UL-1970UL) * SECS_IN_YEAR) + (18UL * SECS_IN_DAY),
   ((2045UL-1970UL) * SECS_IN_YEAR) + (19UL * SECS_IN_DAY),
   ((2046UL-1970UL) * SECS_IN_YEAR) + (19UL * SECS_IN_DAY),
   ((2047UL-1970UL) * SECS_IN_YEAR) + (19UL * SECS_IN_DAY),
   ((2048UL-1970UL) * SECS_IN_YEAR) + (19UL * SECS_IN_DAY),
   ((2049UL-1970UL) * SECS_IN_YEAR) + (20UL * SECS_IN_DAY),
   ((2050UL-1970UL) * SECS_IN_YEAR) + (20UL * SECS_IN_DAY),
   ((2051UL-1970UL) * SECS_IN_YEAR) + (20UL * SECS_IN_DAY),
   ((2052UL-1970UL) * SECS_IN_YEAR) + (20UL * SECS_IN_DAY),
   ((2053UL-1970UL) * SECS_IN_YEAR) + (21UL * SECS_IN_DAY),
   ((2054UL-1970UL) * SECS_IN_YEAR) + (21UL * SECS_IN_DAY),
   ((2055UL-1970UL) * SECS_IN_YEAR) + (21UL * SECS_IN_DAY),
   ((2056UL-1970UL) * SECS_IN_YEAR) + (21UL * SECS_IN_DAY),
   ((2057UL-1970UL) * SECS_IN_YEAR) + (22UL * SECS_IN_DAY),
   ((2058UL-1970UL) * SECS_IN_YEAR) + (22UL * SECS_IN_DAY),
   ((2059UL-1970UL) * SECS_IN_YEAR) + (22UL * SECS_IN_DAY),
   ((2060UL-1970UL) * SECS_IN_YEAR) + (22UL * SECS_IN_DAY),
   ((2061UL-1970UL) * SECS_IN_YEAR) + (23UL * SECS_IN_DAY),
   ((2062UL-1970UL) * SECS_IN_YEAR) + (23UL * SECS_IN_DAY),
   ((2063UL-1970UL) * SECS_IN_YEAR) + (23UL * SECS_IN_DAY),
   ((2064UL-1970UL) * SECS_IN_YEAR) + (23UL * SECS_IN_DAY),
   ((2065UL-1970UL) * SECS_IN_YEAR) + (24UL * SECS_IN_DAY),
   ((2066UL-1970UL) * SECS_IN_YEAR) + (24UL * SECS_IN_DAY),
   ((2067UL-1970UL) * SECS_IN_YEAR) + (24UL * SECS_IN_DAY),
   ((2068UL-1970UL) * SECS_IN_YEAR) + (24UL * SECS_IN_DAY),
   ((2069UL-1970UL) * SECS_IN_YEAR) + (25UL * SECS_IN_DAY),
   ((2070UL-1970UL) * SECS_IN_YEAR) + (25UL * SECS_IN_DAY),
   ((2071UL-1970UL) * SECS_IN_YEAR) + (25UL * SECS_IN_DAY),
   ((2072UL-1970UL) * SECS_IN_YEAR) + (25UL * SECS_IN_DAY),
   ((2073UL-1970UL) * SECS_IN_YEAR) + (26UL * SECS_IN_DAY),
   ((2074UL-1970UL) * SECS_IN_YEAR) + (26UL * SECS_IN_DAY),
   ((2075UL-1970UL) * SECS_IN_YEAR) + (26UL * SECS_IN_DAY),
   ((2076UL-1970UL) * SECS_IN_YEAR) + (26UL * SECS_IN_DAY),
   ((2077UL-1970UL) * SECS_IN_YEAR) + (27UL * SECS_IN_DAY),
   ((2078UL-1970UL) * SECS_IN_YEAR) + (27UL * SECS_IN_DAY),
   ((2079UL-1970UL) * SECS_IN_YEAR) + (27UL * SECS_IN_DAY),
   ((2080UL-1970UL) * SECS_IN_YEAR) + (27UL * SECS_IN_DAY),
   ((2081UL-1970UL) * SECS_IN_YEAR) + (28UL * SECS_IN_DAY),
   ((2082UL-1970UL) * SECS_IN_YEAR) + (28UL * SECS_IN_DAY),
   ((2083UL-1970UL) * SECS_IN_YEAR) + (28UL * SECS_IN_DAY),
   ((2084UL-1970UL) * SECS_IN_YEAR) + (28UL * SECS_IN_DAY),
   ((2085UL-1970UL) * SECS_IN_YEAR) + (29UL * SECS_IN_DAY),
   ((2086UL-1970UL) * SECS_IN_YEAR) + (29UL * SECS_IN_DAY),
   ((2087UL-1970UL) * SECS_IN_YEAR) + (29UL * SECS_IN_DAY),
   ((2088UL-1970UL) * SECS_IN_YEAR) + (29UL * SECS_IN_DAY),
   ((2089UL-1970UL) * SECS_IN_YEAR) + (30UL * SECS_IN_DAY),
   ((2090UL-1970UL) * SECS_IN_YEAR) + (30UL * SECS_IN_DAY),
   ((2091UL-1970UL) * SECS_IN_YEAR) + (30UL * SECS_IN_DAY),
   ((2092UL-1970UL) * SECS_IN_YEAR) + (30UL * SECS_IN_DAY),
   ((2093UL-1970UL) * SECS_IN_YEAR) + (31UL * SECS_IN_DAY),
   ((2094UL-1970UL) * SECS_IN_YEAR) + (31UL * SECS_IN_DAY),
   ((2095UL-1970UL) * SECS_IN_YEAR) + (31UL * SECS_IN_DAY),
   ((2096UL-1970UL) * SECS_IN_YEAR) + (31UL * SECS_IN_DAY),
   ((2097UL-1970UL) * SECS_IN_YEAR) + (32UL * SECS_IN_DAY),
   ((2098UL-1970UL) * SECS_IN_YEAR) + (32UL * SECS_IN_DAY),
   ((2099UL-1970UL) * SECS_IN_YEAR) + (32UL * SECS_IN_DAY),
   ~0
};

const uint_16 _time_days_before_month_internal[2][13] =
{
   {  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, ~0},
   {  0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, ~0}
};

/*
 * The following array contains the number of days between Jan 1, 1970
 * and a given year. For example, to determine the number of days 
 * between Jan 1, 1970 and Jan 1, 1988, the subscript (1988-1970) would
 * be used to index into this table. Note that the first entry is equal to 
 * zero (0).
 *
 */
const uint_32 _time_days_before_year_internal[XCLK_ENTRIES+1] =
{
   ((1970-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (0UL),
   ((1971-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (0UL),
   ((1972-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (0UL),
   ((1973-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (1UL),
   ((1974-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (1UL),
   ((1975-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (1UL),
   ((1976-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (1UL),
   ((1977-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (2UL),
   ((1978-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (2UL),
   ((1979-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (2UL),
   ((1980-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (2UL),
   ((1981-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (3UL),
   ((1982-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (3UL),
   ((1983-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (3UL),
   ((1984-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (3UL),
   ((1985-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (4UL),
   ((1986-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (4UL),
   ((1987-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (4UL),
   ((1988-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (4UL),
   ((1989-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (5UL),
   ((1990-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (5UL),
   ((1991-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (5UL),
   ((1992-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (5UL),
   ((1993-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (6UL),
   ((1994-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (6UL),
   ((1995-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (6UL),
   ((1996-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (6UL),
   ((1997-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (7UL),
   ((1998-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (7UL),
   ((1999-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (7UL),
   ((2000-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (7UL),
   ((2001-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (8UL),
   ((2002-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (8UL),
   ((2003-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (8UL),
   ((2004-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (8UL),
   ((2005-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (9UL),
   ((2006-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (9UL),
   ((2007-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (9UL),
   ((2008-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (9UL),
   ((2009-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (10UL),
   ((2010-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (10UL),
   ((2011-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (10UL),
   ((2012-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (10UL),
   ((2013-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (11UL),
   ((2014-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (11UL),
   ((2015-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (11UL),
   ((2016-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (11UL),
   ((2017-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (12UL),
   ((2018-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (12UL),
   ((2019-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (12UL),
   ((2020-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (12UL),
   ((2021-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (13UL),
   ((2022-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (13UL),
   ((2023-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (13UL),
   ((2024-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (13UL),
   ((2025-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (14UL),
   ((2026-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (14UL),
   ((2027-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (14UL),
   ((2028-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (14UL),
   ((2029-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (15UL),
   ((2030-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (15UL),
   ((2031-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (15UL),
   ((2032-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (15UL),
   ((2033-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (16UL),
   ((2034-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (16UL),
   ((2035-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (16UL),
   ((2036-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (16UL),
   ((2037-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (17UL),
   ((2038-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (17UL),
   ((2039-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (17UL),
   ((2040-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (17UL),
   ((2041-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (18UL),
   ((2042-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (18UL),
   ((2043-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (18UL),
   ((2044-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (18UL),
   ((2045-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (19UL),
   ((2046-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (19UL),
   ((2047-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (19UL),
   ((2048-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (19UL),
   ((2049-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (20UL),
   ((2050-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (20UL),
   ((2051-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (20UL),
   ((2052-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (20UL),
   ((2053-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (21UL),
   ((2054-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (21UL),
   ((2055-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (21UL),
   ((2056-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (21UL),
   ((2057-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (22UL),
   ((2058-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (22UL),
   ((2059-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (22UL),
   ((2060-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (22UL),
   ((2061-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (23UL),
   ((2062-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (23UL),
   ((2063-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (23UL),
   ((2064-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (23UL),
   ((2065-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (24UL),
   ((2066-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (24UL),
   ((2067-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (24UL),
   ((2068-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (24UL),
   ((2069-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (25UL),
   ((2070-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (25UL),
   ((2071-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (25UL),
   ((2072-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (25UL),
   ((2073-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (26UL),
   ((2074-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (26UL),
   ((2075-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (26UL),
   ((2076-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (26UL),
   ((2077-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (27UL),
   ((2078-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (27UL),
   ((2079-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (27UL),
   ((2080-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (27UL),
   ((2081-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (28UL),
   ((2082-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (28UL),
   ((2083-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (28UL),
   ((2084-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (28UL),
   ((2085-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (29UL),
   ((2086-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (29UL),
   ((2087-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (29UL),
   ((2088-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (29UL),
   ((2089-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (30UL),
   ((2090-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (30UL),
   ((2091-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (30UL),
   ((2092-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (30UL),
   ((2093-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (31UL),
   ((2094-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (31UL),
   ((2095-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (31UL),
   ((2096-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (31UL),
   ((2097-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2098-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2099-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2100-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2101-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2102-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2103-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2104-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (32UL),
   ((2105-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (33UL),
   ((2106-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (33UL),
   ((2107-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (33UL),
   ((2108-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (33UL),
   ((2109-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (34UL),
   ((2110-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (34UL),
   ((2111-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (34UL),
   ((2112-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (34UL),
   ((2113-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (35UL),
   ((2114-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (35UL),
   ((2115-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (35UL),
   ((2116-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (35UL),
   ((2117-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (36UL),
   ((2118-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (36UL),
   ((2119-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (36UL),
   ((2120-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (36UL),
   ((2121-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (37UL),
   ((2122-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (37UL),
   ((2123-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (37UL),
   ((2124-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (37UL),
   ((2125-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (38UL),
   ((2126-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (38UL),
   ((2127-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (38UL),
   ((2128-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (38UL),
   ((2129-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (39UL),
   ((2130-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (39UL),
   ((2131-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (39UL),
   ((2132-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (39UL),
   ((2133-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (40UL),
   ((2134-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (40UL),
   ((2135-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (40UL),
   ((2136-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (40UL),
   ((2137-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (41UL),
   ((2138-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (41UL),
   ((2139-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (41UL),
   ((2140-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (41UL),
   ((2141-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (42UL),
   ((2142-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (42UL),
   ((2143-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (42UL),
   ((2144-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (42UL),
   ((2145-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (43UL),
   ((2146-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (43UL),
   ((2147-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (43UL),
   ((2148-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (43UL),
   ((2149-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (44UL),
   ((2150-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (44UL),
   ((2151-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (44UL),
   ((2152-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (44UL),
   ((2153-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (45UL),
   ((2154-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (45UL),
   ((2155-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (45UL),
   ((2156-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (45UL),
   ((2157-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (46UL),
   ((2158-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (46UL),
   ((2159-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (46UL),
   ((2160-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (46UL),
   ((2161-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (47UL),
   ((2162-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (47UL),
   ((2163-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (47UL),
   ((2164-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (47UL),
   ((2165-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (48UL),
   ((2166-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (48UL),
   ((2167-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (48UL),
   ((2168-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (48UL),
   ((2169-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (49UL),
   ((2170-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (49UL),
   ((2171-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (49UL),
   ((2172-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (49UL),
   ((2173-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (50UL),
   ((2174-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (50UL),
   ((2175-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (50UL),
   ((2176-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (50UL),
   ((2177-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (51UL),
   ((2178-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (51UL),
   ((2179-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (51UL),
   ((2180-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (51UL),
   ((2181-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (52UL),
   ((2182-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (52UL),
   ((2183-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (52UL),
   ((2184-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (52UL),
   ((2185-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (53UL),
   ((2186-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (53UL),
   ((2187-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (53UL),
   ((2188-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (53UL),
   ((2189-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (54UL),
   ((2190-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (54UL),
   ((2191-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (54UL),
   ((2192-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (54UL),
   ((2193-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (55UL),
   ((2194-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (55UL),
   ((2195-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (55UL),
   ((2196-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (55UL),
   ((2197-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2198-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2199-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2200-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2201-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2202-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2203-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2204-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (56UL),
   ((2205-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (57UL),
   ((2206-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (57UL),
   ((2207-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (57UL),
   ((2208-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (57UL),
   ((2209-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (58UL),
   ((2210-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (58UL),
   ((2211-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (58UL),
   ((2212-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (58UL),
   ((2213-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (59UL),
   ((2214-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (59UL),
   ((2215-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (59UL),
   ((2216-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (59UL),
   ((2217-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (60UL),
   ((2218-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (60UL),
   ((2219-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (60UL),
   ((2220-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (60UL),
   ((2221-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (61UL),
   ((2222-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (61UL),
   ((2223-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (61UL),
   ((2224-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (61UL),
   ((2225-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (62UL),
   ((2226-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (62UL),
   ((2227-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (62UL),
   ((2228-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (62UL),
   ((2229-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (63UL),
   ((2230-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (63UL),
   ((2231-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (63UL),
   ((2232-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (63UL),
   ((2233-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (64UL),
   ((2234-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (64UL),
   ((2235-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (64UL),
   ((2236-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (64UL),
   ((2237-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (65UL),
   ((2238-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (65UL),
   ((2239-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (65UL),
   ((2240-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (65UL),
   ((2241-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (66UL),
   ((2242-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (66UL),
   ((2243-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (66UL),
   ((2244-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (66UL),
   ((2245-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (67UL),
   ((2246-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (67UL),
   ((2247-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (67UL),
   ((2248-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (67UL),
   ((2249-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (68UL),
   ((2250-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (68UL),
   ((2251-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (68UL),
   ((2252-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (68UL),
   ((2253-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (69UL),
   ((2254-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (69UL),
   ((2255-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (69UL),
   ((2256-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (69UL),
   ((2257-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (70UL),
   ((2258-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (70UL),
   ((2259-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (70UL),
   ((2260-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (70UL),
   ((2261-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (71UL),
   ((2262-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (71UL),
   ((2263-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (71UL),
   ((2264-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (71UL),
   ((2265-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (72UL),
   ((2266-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (72UL),
   ((2267-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (72UL),
   ((2268-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (72UL),
   ((2269-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (73UL),
   ((2270-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (73UL),
   ((2271-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (73UL),
   ((2272-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (73UL),
   ((2273-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (74UL),
   ((2274-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (74UL),
   ((2275-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (74UL),
   ((2276-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (74UL),
   ((2277-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (75UL),
   ((2278-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (75UL),
   ((2279-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (75UL),
   ((2280-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (75UL),
   ((2281-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (76UL),
   ((2282-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (76UL),
   ((2283-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (76UL),
   ((2284-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (76UL),
   ((2285-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (77UL),
   ((2286-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (77UL),
   ((2287-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (77UL),
   ((2288-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (77UL),
   ((2289-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (78UL),
   ((2290-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (78UL),
   ((2291-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (78UL),
   ((2292-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (78UL),
   ((2293-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (79UL),
   ((2294-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (79UL),
   ((2295-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (79UL),
   ((2296-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (79UL),
   ((2297-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2298-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2299-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2300-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2301-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2302-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2303-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2304-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (80UL),
   ((2305-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (81UL),
   ((2306-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (81UL),
   ((2307-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (81UL),
   ((2308-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (81UL),
   ((2309-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (82UL),
   ((2310-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (82UL),
   ((2311-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (82UL),
   ((2312-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (82UL),
   ((2313-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (83UL),
   ((2314-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (83UL),
   ((2315-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (83UL),
   ((2316-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (83UL),
   ((2317-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (84UL),
   ((2318-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (84UL),
   ((2319-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (84UL),
   ((2320-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (84UL),
   ((2321-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (85UL),
   ((2322-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (85UL),
   ((2323-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (85UL),
   ((2324-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (85UL),
   ((2325-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (86UL),
   ((2326-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (86UL),
   ((2327-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (86UL),
   ((2328-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (86UL),
   ((2329-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (87UL),
   ((2330-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (87UL),
   ((2331-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (87UL),
   ((2332-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (87UL),
   ((2333-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (88UL),
   ((2334-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (88UL),
   ((2335-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (88UL),
   ((2336-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (88UL),
   ((2337-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (89UL),
   ((2338-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (89UL),
   ((2339-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (89UL),
   ((2340-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (89UL),
   ((2341-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (90UL),
   ((2342-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (90UL),
   ((2343-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (90UL),
   ((2344-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (90UL),
   ((2345-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (91UL),
   ((2346-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (91UL),
   ((2347-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (91UL),
   ((2348-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (91UL),
   ((2349-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (92UL),
   ((2350-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (92UL),
   ((2351-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (92UL),
   ((2352-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (92UL),
   ((2353-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (93UL),
   ((2354-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (93UL),
   ((2355-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (93UL),
   ((2356-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (93UL),
   ((2357-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (94UL),
   ((2358-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (94UL),
   ((2359-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (94UL),
   ((2360-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (94UL),
   ((2361-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (95UL),
   ((2362-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (95UL),
   ((2363-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (95UL),
   ((2364-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (95UL),
   ((2365-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (96UL),
   ((2366-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (96UL),
   ((2367-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (96UL),
   ((2368-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (96UL),
   ((2369-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (97UL),
   ((2370-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (97UL),
   ((2371-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (97UL),
   ((2372-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (97UL),
   ((2373-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (98UL),
   ((2374-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (98UL),
   ((2375-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (98UL),
   ((2376-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (98UL),
   ((2377-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (99UL),
   ((2378-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (99UL),
   ((2379-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (99UL),
   ((2380-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (99UL),
   ((2381-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (100UL),
   ((2382-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (100UL),
   ((2383-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (100UL),
   ((2384-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (100UL),
   ((2385-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (101UL),
   ((2386-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (101UL),
   ((2387-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (101UL),
   ((2388-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (101UL),
   ((2389-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (102UL),
   ((2390-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (102UL),
   ((2391-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (102UL),
   ((2392-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (102UL),
   ((2393-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (103UL),
   ((2394-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (103UL),
   ((2395-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (103UL),
   ((2396-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (103UL),
   ((2397-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (104UL),
   ((2398-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (104UL),
   ((2399-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (104UL),
   ((2400-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (104UL),
   ((2401-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (105UL),
   ((2402-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (105UL),
   ((2403-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (105UL),
   ((2404-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (105UL),
   ((2405-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (106UL),
   ((2406-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (106UL),
   ((2407-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (106UL),
   ((2408-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (106UL),
   ((2409-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (107UL),
   ((2410-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (107UL),
   ((2411-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (107UL),
   ((2412-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (107UL),
   ((2413-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (108UL),
   ((2414-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (108UL),
   ((2415-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (108UL),
   ((2416-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (108UL),
   ((2417-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (109UL),
   ((2418-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (109UL),
   ((2419-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (109UL),
   ((2420-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (109UL),
   ((2421-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (110UL),
   ((2422-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (110UL),
   ((2423-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (110UL),
   ((2424-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (110UL),
   ((2425-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (111UL),
   ((2426-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (111UL),
   ((2427-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (111UL),
   ((2428-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (111UL),
   ((2429-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (112UL),
   ((2430-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (112UL),
   ((2431-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (112UL),
   ((2432-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (112UL),
   ((2433-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (113UL),
   ((2434-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (113UL),
   ((2435-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (113UL),
   ((2436-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (113UL),
   ((2437-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (114UL),
   ((2438-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (114UL),
   ((2439-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (114UL),
   ((2440-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (114UL),
   ((2441-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (115UL),
   ((2442-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (115UL),
   ((2443-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (115UL),
   ((2444-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (115UL),
   ((2445-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (116UL),
   ((2446-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (116UL),
   ((2447-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (116UL),
   ((2448-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (116UL),
   ((2449-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (117UL),
   ((2450-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (117UL),
   ((2451-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (117UL),
   ((2452-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (117UL),
   ((2453-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (118UL),
   ((2454-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (118UL),
   ((2455-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (118UL),
   ((2456-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (118UL),
   ((2457-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (119UL),
   ((2458-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (119UL),
   ((2459-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (119UL),
   ((2460-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (119UL),
   ((2461-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (120UL),
   ((2462-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (120UL),
   ((2463-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (120UL),
   ((2464-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (120UL),
   ((2465-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (121UL),
   ((2466-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (121UL),
   ((2467-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (121UL),
   ((2468-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (121UL),
   ((2469-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (122UL),
   ((2470-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (122UL),
   ((2471-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (122UL),
   ((2472-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (122UL),
   ((2473-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (123UL),
   ((2474-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (123UL),
   ((2475-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (123UL),
   ((2476-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (123UL),
   ((2477-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (124UL),
   ((2478-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (124UL),
   ((2479-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (124UL),
   ((2480-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (124UL),
   ((2481-XCLK_FIRST_YEAR) * DAYS_IN_YEAR) + (125UL),
   ~0
};

/* EOF */
