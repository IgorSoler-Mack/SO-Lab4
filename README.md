# SO Lab 4: Pipes
Lab 4 de Sistemas operacionais

## Grupo
Igor Soler Cavalcanti - 42013550

Paloma de Sousa Bezerra - 32094264

Rafael Miranda Ferreira - 42080932


# Como Executar o Código
Compile e Execute o arquivo main.c em seu compilador de escolha (GCC foi o Utilizado)

Possíveis comandos para compilar o programa

`make main`

`gcc .\main.c`

Possível comando para executar o programa após compilá-lo
`./main`

## O que o programa faz?
Ao iniciar o programa, um pipe é iniciado, que utiliza uma syscall para criar uma coneção unidicerional entre 2 processos

O Pipe é chamado como um array de tamanho 2

Ex: `int array_pipe[2];`

O `array_pipe[0]` corresponde ao output do Pipe, enquanto o `array_pipe[1]` recebe o input do Pipe

Nessa comunicação de processos, um processos envia os bytes de um dado para o outro escrevendo estes bytes no input do pipe (`array_pipe[1]`) utilizando a função write(), que recebe os bytes de input armazenados no input do pipe, o endereço de memoria onde o dado será armazenado, e o tamanho do dado em bytes.

O segundo processo recebe estes bytes pelo output do pipe (`array_pipe[0]`) e os lê por meio da função read(), que recebe o array do pipe, o endereço de memoria onde o dado lido será armazenado, e o tamanho do dado em bytes.

Utilizando estas funções, o programa inicializa uma variavel `int value = 5;` e então, após gerar o pipe, o programa se bifurca em 2 processos, um pai e um filho. O processo filho adicionar executa `value += 15`, assim gerando um value de 20. 

Entretanto, como o objetivo é passar este valor para o processo pai, o Child Process escreve no pipe o valor de `value` para que ele seja lido pelo Parent.

Para que o Parent Process tenha certeza de que o valor utilizado é o alterado pelo Child Process, ele executa um `wait(NULL)` para esperar que o processo filho termine a execução para continuar, e logo após lê os bytes armazenados no pipe.
