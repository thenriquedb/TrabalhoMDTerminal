# Quantidade de repeticoes desejada
NUM_REPETICOES=50
METODO=a
INSTANCIA=arquivos/graph3.txt
SAIDA=saida.log
PORCENTAGEM=50
# Reseta o contador inicial
CONTADOR=0
# Executa a aplicacao a quantidade de repeticoes especificada
until [ $CONTADOR -ge $NUM_REPETICOES ];
do
echo "Execucao No. $CONTADOR"
echo
./pdif-solver $RANDOM $METODO $INSTANCIA $SAIDA $PORCENTAGEM
# Incrementa o contador
let CONTADOR=CONTADOR+1
done


