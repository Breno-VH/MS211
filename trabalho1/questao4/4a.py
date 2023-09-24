import numpy


#funcao pai
def F(x):
    return numpy.array(
        [[4*x[0] - x[0]**3 + x[1]],
            [-1*(x[0]**2)/9 + (4*x[1] -x[1]**2)/4 + 1]])

#funcao jacobiana com as derivadas parciais
def J(x):
    return numpy.array(
        [[4 - 3*x[0]**2, 1],
        [-2*x[0]/9 , 1 - x[1]/2]])


tol = 1e-25
x=numpy.array([2, 1])

valor_F = F(x)
norma_F = numpy.linalg.norm(valor_F)
itt = 0

while abs(norma_F) > tol and itt <= 100:
    jacob = J(x)
    diff = numpy.linalg.solve(jacob, -valor_F)
    diff = numpy.reshape(diff, (2))
    if numpy.linalg.norm(diff) < tol:
        break 
    x = x + diff
    valor_F = F(x)
    norma_F = numpy.linalg.norm(valor_F)
    itt += 1
print(f'valores de raiz aproximadas encontradas: {x}')
print(f'numero de iteracoes necessarias: {itt}')