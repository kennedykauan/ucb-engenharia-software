Calculadora de Números Binomiais

Projeto acadêmico desenvolvido para a disciplina de **Matemática Aplicada** na *Universidade Católica de Brasília*. O objetivo principal é realizar cálculos matemáticos de fatoriais e coeficientes binomiais sem a utilização de bibliotecas prontas do Python, aplicando lógica de programação pura.

---

## Funcionalidades

- [x] **Cálculo de Fatorial Simples:** Resolução por meio de estruturas de repetição manuais.
- [x] **Análise Combinatória (Coeficiente Binomial):** Aplicação de fórmulas analíticas integradas.
- [x] **Tratamento de Exceções Robustas:** Bloqueio e tratamento para dados não inteiros, caracteres inválidos, números negativos ou cenários matematicamente impossíveis ($p > n$).

---

## Fórmulas Utilizadas

A calculadora realiza as operações utilizando os fundamentos clássicos da análise combinatória:

### Combinação Simples / Coeficiente Binomial
$$C(n,p) = \binom{n}{p} = \frac{n!}{p!(n-p)!}$$

### Fatorial
$$n! = n \times (n-1) \times (n-2) \times \dots \times 1$$

---

## Tecnologias e Conceitos Aplicados

- **Linguagem:** Python 3
- **Modularização:** Uso de funções (`def`) isoladas para garantir o princípio DRY (*Don't Repeat Yourself*).
- **Segurança de Borda:** Blocos `try/except` para impedir a quebra da aplicação por falha do usuário (*Fail-Fast*).

---

## Como Executar

1. Certifique-se de ter o Python instalado.
2. Clone este repositório ou baixe o arquivo fonte.
3. Execute o script via terminal:
   ```bash
   calculadoraNumerosBinomiais.py
