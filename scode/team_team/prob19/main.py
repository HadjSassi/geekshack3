def lreversed(l):
	return [k for k in reversed(l)]

def rankOf(x):
	return x[0]

def nextRankOf(x):
	if x[0] == 'K': return 'god'
	return ranks[ranks.index(x[0]) + 1]

def suitOf(x):
	return x[1]

def scoreOf(x):
	if rankOf(x) in ['J', 'Q', 'K']:
		return 10
	elif rankOf(x) == 'A':
		return 1
	else:
		return ranks.index(rankOf(x)) + 1
def trialScore(t):
	return t[0]

def verbose_automatch(L):
  result = automatch_iter([], [], L, 0)
	print "input: ", L
	print ""
	print "automatch matched score: ", result[0]
	print ""
	print "automatch sequences: "
	for seq in result[2]:
		print seq
		print "automatch groups: "
	for run in result[1]:
		print run
def automatch(L):
	return automatch_iter([], [], L, 0)

def automatch_iter(sets, runs, free, score):
	if free == []:
		return [score, sets, runs]

	maxScore = score
	maxKey = [score, sets, runs]
    l = free[:]
	l.sort(reverse=True, key=lambda u:	
			suits.index(u[1]) * 20 + ranks.index(u[0]))

	streakStart = 0
	streakScore = 0

	for i in range(len(l)):
		if not (i > 0  and suitOf(l[i-1]) == suitOf(l[i])	
				and nextRankOf(l[i]) == rankOf(l[i-1]) ):
			streakStart = i
			streakScore = 0

		streakScore += scoreOf(l[i])
		streakLength = i - streakStart + 1

		if streakLength >= 3:
			trial = automatch_iter(sets,							
					       runs + [lreversed(l[streakStart : i + 1])],		
					       l[0:streakStart] + l[i+1:],				
					       score + streakScore)

			if trialScore(trial) > maxScore:
				maxScore = trialScore(trial)
				maxKey = trial
	l = free[:]
	l.sort(reverse=True, key=rankOf)

	streakStart = 0
	streakScore = 0

	for i in range(len(l)):
		if not (i > 0 and rankOf(l[i - 1]) == rankOf(l[i])):
			streakStart = i
			streakScore = 0

		streakScore += scoreOf(l[i])
		streakLength = i - streakStart + 1

		if streakLength == 5:
			streakLength = 0
			streakScore = scoreOf(l[i])

		if streakLength in [3,4]:
			trial = automatch_iter(sets + [lreversed(l[streakStart : i + 1])],		
					       runs,							
					       l[0:streakStart] + l[i+1:],				
					       score + streakScore)

			if trialScore(trial) > maxScore:
				maxScore = trialScore(trial)
				maxKey = trial
return maxKey 