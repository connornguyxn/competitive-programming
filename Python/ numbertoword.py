one_digit = ["không", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"]
units = ["", " mốt", " hai", " ba", " bốn", " lăm", " sáu", " bảy", " tám", " chín"]
tens = ["linh", "mười"] + [x + " mươi" for x in ["hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"]]
hundreds = [x + " trăm" for x in one_digit]
bigger = ["", " nghìn", " triệu"]


def conv(number):
	n = int()
	if (len(number) == 1):
		return one_digit[n]
	elif (len(number) == 2):
		return tens[n//10] + units[n%10]
	else:
		if number == '000':
			return ''
		elif (n//10)%10 == 0:  # x0y
			if n % 10 == 0:  # x00
				return hundreds[n//100]
			else:
				return hundreds[n//100] + ' ' + tens[(n//10)%10] + ' ' + one_digit[n%10]
		else:  # xyz
			return hundreds[n//100] + ' ' + tens[(n//10)%10] + units[n%10]


def read_billion_group(number):
	classes = []
	for i in range(len(number)-1, 1, -3):
		classes.append(number[i-2:i+1])
	
	if len(number) % 3 != 0:
		classes.append(number[:len(number)%3])
	
	res = ''
	for i in range(len(classes)):
		named_class = read_class(classes[i])
		if named_class != '':
			res = named_class + bigger[i] + (' ' * (res != '')) + res

	return res


while True:
	try:
		number = input()
	except:
		break

	number = number.lstrip('0').rstrip('\n')
	billion_groups = []
	for i in range(len(number)-1, 7, -9):
		billion_groups.append(number[i-8:i+1])
	
	if len(number) % 9 != 0:
		billion_groups.append(number[:len(number)%9])

	res = ''
	for i in range(len(billion_groups)-1, -1, -1):
		group_name = read_billion_group(billion_groups[i])

		if group_name != '':
			res += group_name + ' tỉ' * i + (', ' * (i != 0))

	print(res)