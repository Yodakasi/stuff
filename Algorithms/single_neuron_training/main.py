import numpy as np

def linearFunc(num):
    if num < 0:
        return 0
    return 1


def getInput():
    n = float(input("Enter learning rate 0-1:\n"))
    get = "start"
    L = []
    k = 1
    while len(get) > 4:
        get = input("Enter "+str(k)+" set of learning data (comma separated) with desired output at the end:\n")
        get = "1.0," + get
        L.append(get.split(','))
        k += 1
    wages = input("Enter wages (comma separated) ex. w0, w1, w2 for neuron with 2 inputs(w0 is wage for bias):\n")
    wages = wages.split(',')
    print(L)
    print(wages)
    return L[:-1], wages, n


if __name__ == "__main__":
    LStr, wageStr, n = getInput()#[['1.0', '0.1', '0.9', '1'], ['1.0', '1.0', '0.1', '0']], ['0.1', '-0.1', '-0.2'], 0.1
    dataNum = len(LStr)
    L = []
    wage = []
    k, t, lpd = 0, 0, 0
    for i in LStr:
        L.append(list(map(float, i)))
    wage = list(map(float, wageStr))
    while lpd < dataNum:
        y = linearFunc(np.matmul(wage, [[i] for i in L[k][:-1]])[0])
        if y == L[k][-1]:
            lpd += 1
        else:
            lpd = 0
            wage = np.add(wage, np.multiply(n*(L[k][-1] - y), L[k][:-1]))
        print("Iteration nr. ", t)
        print("Wages: ", wage)
        t += 1
        k = (k + 1) % dataNum
