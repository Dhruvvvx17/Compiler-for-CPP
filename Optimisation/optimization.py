import re
import sys
icg_file = "ICG.code"

istemp = lambda s : bool(re.match(r"^t[0-9]*$", s)) 
isid = lambda s : bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s)) #will match temp also

binary_operators = {"+", "-", "*", "/", "*", "&", "|", "^", ">>", "<<", "==", ">=", "<=", "!=", ">", "<"}

def printicg(list_of_lines, message = "") :
	print(message.upper())
	for line in list_of_lines :
		print(line.strip())

def eval_wrap(line,dict_var) :
	tokens = line.split()
	if (len(tokens) != 4 and len(tokens)!= 6) :
		return line
	if(len(tokens)==4):
		
		if(tokens[3] in dict_var):
			dict_var[tokens[1]] = dict_var[tokens[3]]
			return tokens[0] + " " + tokens[1] + " " + tokens[2] + " " + str(dict_var[tokens[3]])
		#elif(isid(tokens[1]) and not(isid(tokens[3]))):
		#	dict_var[tokens[1]] = int(tokens[3])
			return line
		else:
			return line
	else:
		if(tokens[3] in dict_var):
			tokens[3]=str(dict_var[tokens[3]])
		if(tokens[5] in dict_var):
			tokens[5]=str(dict_var[tokens[5]])
		if tokens[2] != "=" or tokens[4] not in binary_operators:
			return " ".join([tokens[0],tokens[1],tokens[2],tokens[3],tokens[4],tokens[5]])
		#tokens = tokens[2:]
		if tokens[3].isdigit() and tokens[5].isdigit() :
			result = eval(str(tokens[3] + tokens[4] + tokens[5]))
			dict_var[tokens[1]]=result
			return " ".join([tokens[0],tokens[1], tokens[2], str(result)])
		if tokens[3].isdigit() or tokens[5].isdigit() : #Replace the identifier with a number and evaluate
			op1 = tokens[3]
			op2 = tokens[5]
			op = tokens[4]
			try : 
				result = int(eval(op1+op+op2))
				dict_var[tokens[1]]=result
				return " ".join([tokens[0],tokens[1],tokens[2],str(result)])

			except NameError :
				return " ".join([tokens[0],tokens[1],tokens[2],tokens[3],tokens[4],tokens[5]])
			except ZeroDivisionError :
				print("Division By Zero is undefined")
				quit()
		return " ".join([tokens[0],tokens[1],tokens[2],tokens[3],tokens[4],tokens[5]])
	

def fold_constants(list_of_lines,dict_var) :
	"""
	Some expressions that can have a definite answer need not be waste run time resources :
	e.g.
	1. number + number, number - number etc.
	2. identifier + 0, identfier / 0, identifer - 0, identifier*0 and their commutatives
	3. identifier * 1, identifier / 1
	"""

	new_list_of_lines = []
	for line in list_of_lines :
		new_list_of_lines.append(eval_wrap(line,dict_var))
	return new_list_of_lines

def correct_line(list_of_lines):
	cnt = 0
	dict_line = {}
	dict_line_not = {}
	new_list_of_lines = []
	for line in list_of_lines:
		tokens = line.split()
		t = int(tokens[0].split(":")[0])
		if(t != cnt):
			dict_line_not[str(cnt)] = str(t)
			cnt += 1
		cnt += 1
	cnt = 0
	flag = 0
	lin_no = 0
	for line in list_of_lines:
		tokens = line.split()
		t = int(tokens[0].split(":")[0])
		if(t - lin_no != cnt):
			lin_no += 1
		dict_line[str(t)] = str(t - lin_no)
		tokens[0]= str(t - lin_no) + ":"
		line = " ".join([tokens[i] for i in range(0,len(tokens))])
		new_list_of_lines.append(line)
		cnt += 1
	fin_list_of_lines = []
	for line in new_list_of_lines:
		tokens = line.split()
		if(len(tokens)==3):
			if(tokens[1]=="goto"):
				if(tokens[2] in dict_line_not):
					tokens[2] = dict_line_not[tokens[2]]
				tokens[2] = dict_line[tokens[2]]
				line = " ".join([tokens[i] for i in range(0,len(tokens))])
				fin_list_of_lines.append(line)
		elif(len(tokens)==5):
			if(tokens[3]=="goto"):
				if(tokens[4] in dict_line_not):
					tokens[4] = dict_line_not[tokens[4]]
				tokens[4] = dict_line[tokens[4]]
				line = " ".join([tokens[i] for i in range(0,len(tokens))])
				fin_list_of_lines.append(line)
		else:
			fin_list_of_lines.append(line)
	return fin_list_of_lines
def remove_dead_code(list_of_lines) :
	"""
Temporaries that are never assigned to any variable nor used in any expression are deleted. Done recursively.
	"""
	num_lines = len(list_of_lines)
	print("number of lines = ",num_lines)
	temps_on_lhs = set()
	for line in list_of_lines :
		tokens = line.split()
		if(istemp(tokens[1])):
			temps_on_lhs.add(tokens[1])

	useful_temps = set()
	for line in list_of_lines :
		tokens = line.split()
		if(len(tokens)==5):	
			useful_temps.add(tokens[2])
		elif(len(tokens)>2):
			for i in range(3,len(tokens)):
				useful_temps.add(tokens[i])
	temps_to_remove = temps_on_lhs - useful_temps
	new_list_of_lines = []
	for line in list_of_lines :
		tokens = line.split()
		if len(tokens)==2 or tokens[1] not in temps_to_remove :
			new_list_of_lines.append(line)
	if num_lines == len(new_list_of_lines) :
		return correct_line(new_list_of_lines)
	return remove_dead_code(new_list_of_lines)

"""
def wrap_temps(list_of_lines, unique_temps = 100) :
	temps_for_reuse = set()
	number_of_lines = len(list_of_lines)
	for i in range(number_of_lines) :
		tokens = list_of_lines[i].split()
		if len(tokens) == 5 and istemp(tokens[4]) : #a temp has been assigned to something else
"""
def make_subexpression_dict(list_of_lines) :
	expressions = {}
	variables = {}
	for line in list_of_lines :
		tokens = line.split()
		if len(tokens) == 6 :
			# print("variables",variables)
			if tokens[1] in variables and variables[tokens[1]] in expressions :
				print(tokens[1], variables[tokens[1]], expressions[variables[tokens[1]]])
				del expressions[variables[tokens[1]]]
			rhs = tokens[3] + " " + tokens[4] + " " + tokens[5]
			if rhs not in expressions :
				expressions[rhs] = tokens[1]
				if isid(tokens[3]) :
					variables[tokens[3]] = rhs
				if isid(tokens[5]) :
					variables[tokens[5]] = rhs
	return expressions

def eliminate_common_subexpressions(list_of_lines) :
	expressions = make_subexpression_dict(list_of_lines)
	lines = len(list_of_lines)
	new_list_of_lines = list_of_lines[:]
	for i in range(lines) :
		tokens = list_of_lines[i].split()
		if len(tokens) == 6 :
			rhs = tokens[3] + " " + tokens[4] + " " + tokens[5]
			if rhs in expressions and expressions[rhs] != tokens[1]:
				new_list_of_lines[i] = tokens[0] + " " + tokens[1] + " " + tokens[2] + " " + expressions[rhs]
	return new_list_of_lines
				

if __name__ == "__main__" :

	if len(sys.argv) == 2 :
		icg_file = str(sys.argv[1])
	
	list_of_lines = []
	f = open(icg_file, "r")
	for line in f :
		list_of_lines.append(line)
	f.close()
	dict_var ={}
	printicg(list_of_lines, "ICG")
	#
	folded_constants = fold_constants(list_of_lines,dict_var)
	printicg(folded_constants, "Optimized ICG after constant folding and variable propogation")
	#	
	eliminated_common_subexpressions = eliminate_common_subexpressions(folded_constants)
	printicg(eliminated_common_subexpressions, "Optimized ICG after eliminating common subexpressions")
	
	without_deadcode = remove_dead_code(eliminated_common_subexpressions)
	printicg(without_deadcode, "Optimized ICG after removing dead code")
	print("Eliminated",0, "lines of code")
	
