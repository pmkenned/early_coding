f = open("mandelbrot.txt", "a")
b = 0-1.25j
import os
while(b.imag < 1.25):
	a = -2
	while(a < .5):
		i=0
		z=0+0j
		while(i < 25):
			if z.real>10000 or z.imag>10000:
				f.write(str(b.imag))
				f.write("\n")
				f.write(str(a))
				f.write("\t")
				i=25
			z = pow(z, 2)+a+b
			i = i+1
		a = a + .01
	os.system('cls')
	b = b + .01j
	print (b.imag+1.25)/2.5 * 100, "%"
f.close()