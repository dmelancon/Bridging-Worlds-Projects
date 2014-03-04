from temboo.core.Library.Google.Calendar import GetAllEvents
from temboo.core.session import TembooSession
from datetime import datetime
import time
import calendar as cal
# Instantiate the Choreo, using a previously instantiated TembooSession object, eg:
session = TembooSession(YOURNAME, 'myFirstApp', YOURID)
getAllEventsChoreo = GetAllEvents(session)

# Get an InputSet object for the choreo
getAllEventsInputs = getAllEventsChoreo.new_input_set()

# Set credential to use for execution
getAllEventsInputs.set_credential('calendar')

# Set inputs
getAllEventsInputs.set_CalendarID("3cda5tqb0q6ppsrmg59ndm869c@group.calendar.google.com")

# Execute choreo
getAllEventsResults = getAllEventsChoreo.execute_with_results(getAllEventsInputs)
results = getAllEventsResults.get_Response()

#print results

import json
js = json.loads(results)
ourResult = js['items']
events = dict()
for rs in ourResult:
	events[str(rs['summary'])] = str(rs['start']['dateTime'])

for event in events:
    ISOtime  = events[event]
	#strip the timezone because time.mktime already assumes local time
    ISOtime = ISOtime.replace(ISOtime[-6:],"")
#convert ISOtime to UNIX timecode
    UNIXtime = time.mktime(time.strptime(ISOtime,'%Y-%m-%dT%H:%M:%S'))
#current Unix Timestamp as an INT
    timestamp = int(time.time())    
#subtract Unix Timestamp from the event unix time to get time until event
    timeLeft = int(UNIXtime-timestamp)
    print timeLeft
    print event +","+ str(timeLeft)

