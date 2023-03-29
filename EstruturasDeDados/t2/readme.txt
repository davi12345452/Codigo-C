- Funções não declaradas dentro do str.h e que foram declaradas no str.c, devem ser declaradas com
static antes, pois senão serão interpretadas como funções globais e poderão ser acessadas pelo usu-
ário, enquanto queremos usá-la internamente de str.c