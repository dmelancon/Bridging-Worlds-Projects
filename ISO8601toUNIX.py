from datetime import datetime
import time
import calendar as cal
#This simple script will take an EVENT time in ISO8601 and return the time in seconds until that event
ISOtime = "2014-03-04T13:11:00-05:00"  #time of event in ISO8601  
 
#strip the timezone because time.mktime alreadu assumes local time
ISOtime = ISOtime.replace(ISOtime[-6:],"")
#convert ISOtime to UNIX timecode
UNIXtime = time.mktime(time.strptime(ISOtime,'%Y-%m-%dT%H:%M:%S'))
#subtract timezone from unix to show correct time
timestamp = int(time.time())    #current Unix Timestamp as an INT
timeLeft = int(UNIXtime-timestamp)
print timeLeft
