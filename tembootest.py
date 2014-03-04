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
        originald = events[event]
	#delete T form string for formatting
        originald = originald.replace("T", " ")
	#strip timezone and save as variable for unix time
        timezone = float(originald[-6:].replace(":","."))
        originald = originald.replace(originald[-6:],"")
        event_unix = time.mktime(time.strptime(originald,'%Y-%m-%d %H:%M:%S'))
       #subtract timezone from unix to show correct time
        timestamp = int(time.time())
        print timestamp
        print event_unix
        timeLeft = int(event_unix-timestamp)
        print event +","+ str(timeLeft)

