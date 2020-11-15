print "This program caculates the roots of a quadratic equation"
a = float(raw_input("Enter a:"))
b = float(raw_input("Enter b:"))
c = float(raw_input("Enter c:"))
desc = b*b-4*a*c
if desc == 0:
	print ("Double root:")
	print (-1*b + pow(b*b-4*a*c, .5))/(2*a)
if desc > 0:
	print ("Two real roots:")
	print (-1*b + pow(b*b-4*a*c, .5))/(2*a)
	print (-1*b - pow(b*b-4*a*c, .5))/(2*a)
if desc < 0:
	print ("Two imaginary roots:")
	print -1*b,"+ i",u"\u221a",-1*desc
	print -1*b,"- i",u"\u221a",-1*desc
