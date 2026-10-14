# função para calcular o fatorial de um número
def calcularFatorial(numero):
    if numero == 0 or numero == 1:
        return 1
    fatorial = 1
    contador = numero
    while contador > 0:
        fatorial *= contador
        contador -= 1
    return fatorial

# fórmula para descobrir o coeficiente binomial
def calcularBinomial(n, p):

    if p > n:
        print(f"Erro: 'p' ({p}) é maior que 'n' ({n})")
        return None
    if n < 0 or p < 0:
        print(f"Erro: Os números não podem ser negativos.")
        return None

    # fórmula
    fatorialN = calcularFatorial(n)
    fatorialP = calcularFatorial(p)
    fatorialNmenosP = calcularFatorial(n - p)

    resultado = fatorialN // (fatorialP * fatorialNmenosP)
    return resultado

print('-' * 50)
print('Bem Vindo à calculadora de números binomiais')
print('-' * 50)

while True:

# input/entrada de dados
    try:
        tipoDeOperacao = int(input('Qual operação deseja realizar? \n Fatorial[1] \n Coeficiente binomial[2] \n'))
    except ValueError:
        print("Erro: Por favor, digite apenas números inteiros válidos")
        continue

# calculadora de fatorial
    if tipoDeOperacao == 1:
        print('-' * 50)
        print('CALCULADORA DE FATORIAL')

        try:
            numero = int(input('\nDigite um número para saber o seu fatorial: '))
        except ValueError:
            print("Erro: apenas valores inteiros são permitidos")
            continue

        if  numero < 0:
            print(f'O valor de {numero} é negativo. Não existe fatorial de número negativo')
        else:
            print(f'O fatorial de {numero} é {calcularFatorial(numero)}')

# coeficiente binomial
    elif tipoDeOperacao == 2:
        print('-' * 50)
        print('CALCULADORA DE COEFICIENTE BINOMIAL')

        try:
            numeroN = int(input('\nDigite o valor de N (total de elementos): '))
            numeroP = int(input('Digite o valor de P (elementos escolhidos): '))
        except ValueError:
            print("Erro: Valores inteiros ou inválidos detectados")
            continue
        resultadoBinomial = calcularBinomial(numeroN, numeroP)

        if resultadoBinomial is not None:
            print(f"O coeficiente binomial de {numeroN} escolhe {numeroP} é: {resultadoBinomial}")
    else:
        print("Opção inválida escolha 1 ou 2.")

    print('-' * 50)
    resposta = str(input('Quer realizar outra operação? [S/N] ')).strip().upper()

    if resposta == 'N':
        break
print("\n CALCULADORA ENCERRADA.")