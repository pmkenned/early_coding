principle = float(raw_input("Principle: "))
rate = float(raw_input("Interest Rate: "))
n = float(raw_input("Number of times paid per year: "))
time = float(raw_input("Years: "))
print principle * pow(1+(.01*rate/n), (n*time))
raw_input