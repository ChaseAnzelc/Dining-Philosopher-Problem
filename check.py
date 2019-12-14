import sys
import re

stIdx = {"START":-1, "THINKING":0, "HUNGRY":1, "FIRST":2, "SECOND":3, "EATING":4}

def main():

	if len(sys.argv) < 2:
		print("Usage: python check.py <integer>")
		return
	try:
		phCount = int(sys.argv[1])
	except:
		print("Usage: python check.py <integer>")
		return

	phStates = ["START"] * phCount

	logfile = open("log.txt","r")
	line_cnt = 0
	for line in logfile:
		#print line,
		line_cnt += 1
		match = re.search("PHILOSOPHER *(\d+):.*(THINKING|HUNGRY|FIRST|SECOND|EATING)",line.upper())
		if match:
			print match.group(1), match.group(2)
			#print "(%s) (%s)" % (match.group(1), match.group(2))
			phID, new_state = int(match.group(1)), match.group(2)
			if stIdx[new_state] != (stIdx[phStates[phID]] + 1) % 5: 
				print "-- Action out of order at line %d --" % line_cnt
				print line, 
				return
			phStates[phID] = new_state
			if new_state == "EATING":
				left_phID = (phID + phCount -1) % phCount
				right_phID = (phID + 1) % phCount
				if phStates[left_phID] ==  "EATING":
					print "Line %d --> Philosopher %d and %d can't EAT at the same time" % (line_cnt, phID, left_phID)
					return
				if phStates[right_phID] ==  "EATING":
					print "Line %d --> Philosopher %d and %d can't EAT at the same time" % (line_cnt, phID, right_phID)
					return

	if not re.search("DONE",line.upper()):
		print "===> Not finished in the right way. Deadlock?"
	else:
		print "*** The log file looks good."
	logfile.close()
		
main()

