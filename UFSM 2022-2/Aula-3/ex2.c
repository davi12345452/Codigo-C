#include <stdio.h>

#define MILHAS_KM 1.609
#define GALAO_L 3.79

int main(){

    float odo_i, odo_f;
    float t_combustivel;
    float km_l, m_galao, l_porCemKm;

    printf("\nOdometro inicial: ");
    scanf("%f", &odo_i);

    printf("\nOdometro final: ") ;
    scanf("%f", &odo_f);

    printf("\nLitros para encher o tanque apos a viagem: ");
    scanf("%f", &t_combustivel);

    km_l = (odo_f - odo_i)/t_combustivel;
    m_galao = ((odo_f - odo_i)/MILHAS_KM) / (t_combustivel/GALAO_L);
    l_porCemKm = 100 / km_l;

    printf("\nKilometros por litro: %f\nMilhas por galao: %f\nLitros para 100km: %f\n", km_l, m_galao, l_porCemKm);
    return 0;
}
