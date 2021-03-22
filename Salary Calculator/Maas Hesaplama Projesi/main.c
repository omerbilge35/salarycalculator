#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   char calisan,medeni_hal,es_durum,engel,adsoyad[50],eyb_isim[50],eyn_isim[50];
   int i,cocuk_sayisi,buyuk6,kucuk6,engel_orani,es_yardim,cocuk_yardim=0,engel_derecesi=0,es_calisan=0,toplam_cocuk=0;
   int tb200=0,tb100=0,tb50=0,tb20=0,tb10=0,tb5=0,tm100=0,tm50=0,tm25=0,tm10=0,tm5=0,tm1=0,calisan_sayisi=0,maas2000_alti=0;
   int b200=0,b100=0,b50=0,b20=0,b10=0,b5=0,m100=0,m50=0,m25=0,m10=0,m5=0,m1=0,engelli_calisan=0;
   int vergi15=0,vergi20=0,vergi27=0,vergi35=0,evli_sayisi=0,bekar_sayisi=0,cocuklu_calisan=0,uc_cocuk=0;
   float asgari_ucret=1777.50,brut_ucret,toplam_brut=0,gelir_vergisi=0,aylik_net=0,indirimli_brut=0,para_hesap,ort_cocuk=0;
   float toplam_tbrut=0,toplam_aylik_net=0,toplam_vergi=0,eyn_brut,eyb_net,eyb_vergi,eyn_vergi,yuzde_es_calisan=0,yuzde_engelli;
   float yuzde15=0,yuzde20=0,yuzde27=0,yuzde35=0,enyuksek_brut=0,enyuksek_net=0,yuzde_evli,yuzde_bekar;
   double tcno,eyb_tcno,eyn_tcno;
   calisan='e';
    for(i=1;i>0;i++){
        engel_derecesi=0;
        if(calisan=='e' || calisan=='E'){

                printf(" TC kimlik numaranizi giriniz:");
                  scanf("%lf",&tcno);
                  fflush(stdin);

                printf("\n Ad Soyad giriniz:");
                  gets(adsoyad);

                printf("\n Aylik brut ucretinizi giriniz (TL):");
                scanf("%f",&brut_ucret);
                  if (brut_ucret<asgari_ucret){
                    brut_ucret=asgari_ucret;
                 }
                 for(i=1;i>0;i++){
                printf("\n Evli misiniz?(E/e,H/h):");
                scanf("%s",&medeni_hal);

                  if (medeni_hal == 'E' || medeni_hal == 'e'){
                        evli_sayisi++;
                    for(i=1;i>0;i++){
                    printf("\n Esiniz calisiyor mu?(E/e,H/h):");
                    scanf("%s",&es_durum);
                    if (es_durum == 'E' || es_durum == 'e'){
                            es_calisan++;
                        es_yardim=0;
                        toplam_brut=brut_ucret+es_yardim;
                        break;
                 }
                      else if (es_durum == 'H' || es_durum == 'h')  {
                          es_yardim=220;
                          toplam_brut=brut_ucret+ es_yardim;
                        break;
                      }
                  }
                   break;
               }

                      else if (medeni_hal == 'H' || medeni_hal == 'h'){
                       bekar_sayisi++;
                       toplam_brut=brut_ucret;
                        break;
                      }
               }

               for(i=1;i>0;i++){

                printf("\n Bakmakla yukumlu oldugunuz cocuk sayisi (0 veya daha buyuk): ");
                  scanf("%d",&cocuk_sayisi);
                  toplam_cocuk+=cocuk_sayisi;
                    if (cocuk_sayisi>0){

                            if(cocuk_sayisi>3){
                                uc_cocuk++;
                               }
                            cocuklu_calisan++;
                            for(i=1;i>0;i++){

                        printf("\n 6 yasindan buyuk olan cocuk sayisi: ");
                          scanf("%d",&buyuk6);
                  if (buyuk6>=0 && buyuk6<=cocuk_sayisi){

                        kucuk6=cocuk_sayisi-buyuk6;
                        cocuk_yardim=(kucuk6*25)+(buyuk6*45);

                        toplam_brut=toplam_brut+cocuk_yardim;
                       break;
                        }

                 }
             break;
            }
                    else if (cocuk_sayisi==0){
                        break;
                        }
                }
         for(i=1;i>0;i++){
             printf("\n Herhangi bir engeliniz var mi? (E/e,H/h): ");
              scanf("%s",&engel);
               if (engel=='E' || engel=='e'){
                    engelli_calisan++;
                for (i=1;i>0;i++){
                    printf("\n Engel orani (1 ya da daha buyuk ve 100 ya da daha kucuk):  ");
                     scanf("%d",&engel_orani);


                if (engel_orani>0  && engel_orani<40){
                      indirimli_brut=toplam_brut;
                   break;
                }

               else if (engel_orani>=40 && engel_orani<60){
                    engel_derecesi=1;
                indirimli_brut=toplam_brut-210;
               break;
              }

             else if (engel_orani>=60 && engel_orani<80){
                    engel_derecesi=2;
                indirimli_brut=toplam_brut-470;
             break;
                }

            else if (engel_orani>=80 && engel_orani<=100){
                    engel_derecesi=3;
                indirimli_brut=toplam_brut-900;
           break;
            }


               }
               break;
               }
              else if (engel=='H' || engel=='h'){
              indirimli_brut=toplam_brut;
          break;
         }
               }

         if (indirimli_brut<2000){
                    gelir_vergisi=indirimli_brut*(15/100.00);
                    aylik_net=toplam_brut-gelir_vergisi;
                    vergi15++;
                }
                else if (indirimli_brut>=2000 && indirimli_brut<5000){
                    gelir_vergisi=indirimli_brut*(20/100.00);
                    aylik_net=toplam_brut-gelir_vergisi;
                    vergi20++;
                }
                else if (indirimli_brut>=5000 && indirimli_brut<10000){
                    gelir_vergisi=indirimli_brut*(27/100.00);
                    aylik_net=toplam_brut-gelir_vergisi;
                    vergi27++;
              }
               else if (indirimli_brut>=10000){
                    gelir_vergisi=indirimli_brut*(35/100.00);
                    aylik_net=toplam_brut-gelir_vergisi;
                    vergi35++;
              }


       printf("\n \n");
       printf("~~~~ CALISAN BILGILERI ~~~~\n\n");
       printf(" TC kimlik NO:%.0lf \n\n",tcno);
       printf(" Ad Soyad:");
       printf(adsoyad);
       printf("\n\n");
       printf(" Aylik brut ucretiniz:%.2f TL \n\n",brut_ucret);
       printf(" Es icin aile yardim odenegi:%d TL\n\n",es_yardim);
       printf(" Cocuk icin aile yardim odenegi:%d TL\n\n",cocuk_yardim);
       printf(" Aylik toplam brut:%.2f TL\n\n",toplam_brut);
       printf(" Gelir vergisi kesintisi:%.2f TL\n\n",gelir_vergisi);
       if (engel_derecesi>0){
        printf(" Engel derecesi:%d\n\n",engel_derecesi);
       }
       printf(" Aylik net:%.2f TL\n\n",aylik_net);
//BANKNOT HESAPLAMA
     printf("~~~ Maas Icin Gerekli Banknotlar ~~~\n\n");
      para_hesap=aylik_net;
     if(para_hesap>=200){
       b200=para_hesap/200;
       para_hesap=para_hesap-(b200*200);
       printf("\t%d tane 200'luk\n",b200);
         tb200+=b200;
    }
    if(para_hesap>=100){
        b100=para_hesap/100;
        para_hesap=para_hesap-(b100*100);
        printf("\t%d tane 100'luk\n",b100);
          tb100+=b100;
   }
    if(para_hesap>=50){
        b50=para_hesap/50;
        para_hesap=para_hesap-(b50*50);
        printf("\t%d tane 50'lik\n",b50);
          tb50+=b50;
   }
    if(para_hesap>=20){
        b20=para_hesap/20;
        para_hesap=para_hesap-(b20*20);
        printf("\t%d tane 20'lik\n",b20);
           tb20+=b20;
   }
     if(para_hesap>=10){
        b10=para_hesap/10;
        para_hesap=para_hesap-(b10*10);
        printf("\t%d tane 10'luk\n",b10);
           tb10+=b10;
   }
   if(para_hesap>=5){
       b5=para_hesap/5;
       para_hesap=para_hesap-(b5*5);
       printf("\t%d tane 5'lik\n",b5);
           tb5+=b5;
   }
    if(para_hesap>=1){
        m100=para_hesap/1;
        para_hesap=para_hesap-(m100*1);
        printf("\t%d tane 1'lik\n",m100);
            tm100+=m100;
   }
    if(para_hesap>=0.5){
        m50=para_hesap/0.5;
        para_hesap=para_hesap-(m50*0.5);
        printf("\t%d tane 50 kurus\n",m50);
            tm50+=m50;
   }
    if(para_hesap>=0.25){
        m25=para_hesap/0.25;
        para_hesap=para_hesap-(m25*0.25);
        printf("\t%d tane 25 kurus\n",m25);
             tm25+=m25;
   }
    if(para_hesap>=0.10){
        m10=para_hesap/0.10;
        para_hesap=para_hesap-(m10*0.10);
        printf("\t%d tane 10 kurus\n",m10);
            tm10+=m10;
   }
    if(para_hesap>=0.05){
        m5=para_hesap/0.05;
        para_hesap=para_hesap-(m5*0.05);
        printf("\t%d tane 5 kurus\n",m5);
            tm5+=m5;
   }
    if(para_hesap>=0.01){
        m1=para_hesap/0.01;
        para_hesap=para_hesap-(m1*0.01);
        printf("\t%d tane 1 kurus\n",m1);
            tm1+=m1;
   }

       printf("\n\n");

       toplam_tbrut=toplam_tbrut+toplam_brut;
       toplam_aylik_net=toplam_aylik_net+aylik_net;
       toplam_vergi=toplam_vergi+gelir_vergisi;
       calisan_sayisi++;
       if(aylik_net<2000){
        maas2000_alti++;
       }
      yuzde15=(vergi15*100)/calisan_sayisi;
      yuzde20=(vergi20*100)/calisan_sayisi;
      yuzde27=(vergi27*100)/calisan_sayisi;
      yuzde35=(vergi35*100)/calisan_sayisi;

      if(aylik_net>enyuksek_net){
        eyn_tcno=tcno;
        eyn_isim[0]='\0';
        strcat(eyn_isim,adsoyad);
        eyn_brut=toplam_brut;
        eyn_vergi=gelir_vergisi;
        enyuksek_net=aylik_net;
      }

      if(toplam_brut>enyuksek_brut){
        eyb_tcno=tcno;
        eyb_isim[0]='\0';
        strcat(eyb_isim,adsoyad);
        eyb_net=aylik_net;
        eyb_vergi=gelir_vergisi;
        enyuksek_brut=toplam_brut;
      }

     yuzde_evli=(evli_sayisi*100)/calisan_sayisi;
     yuzde_bekar=(bekar_sayisi*100)/calisan_sayisi;
    if(evli_sayisi>0){
     yuzde_es_calisan=(es_calisan*100)/evli_sayisi;
    }
     if(cocuklu_calisan>0){
     ort_cocuk=toplam_cocuk/cocuklu_calisan;
     }

    yuzde_engelli=(engelli_calisan*100)/calisan_sayisi;

        }
    else if(calisan=='h' || calisan=='H'){
       break;
    }
     printf(" Baska calisan var mi?(E/e , H/h):");
    scanf("%s",&calisan);
    printf("\n\n");
     } //İSTATİSTİK BÖLÜMÜ
     printf("~~~ Tum Calisanlarin Istatistikleri ~~~\n\n");
     printf(" Tum calisanlara odenen aylik net ucret:%.2f TL\n",toplam_aylik_net);
     printf(" Devlete aktarilan toplam gelir vergisi:%.2f TL\n",toplam_vergi);
     printf(" Toplam brut ucret ortalamasi:%.2f TL\n",toplam_tbrut/calisan_sayisi);
     printf(" Toplam net ucret ortalamasi:%.2f TL\n",toplam_aylik_net/calisan_sayisi);
     printf(" 2000 TL'den az maas alan calisanlarin sayisi:%d\n",maas2000_alti);
     printf(" Evli calisanlarin yuzdesi:%.2f\n",yuzde_evli);
     printf(" Bekar calisanlarin yuzdesi:%.2f\n",yuzde_bekar);
     printf(" Evli calisanlar icinde esi de calisanlarin yuzdesi:%.2f\n",yuzde_es_calisan);
     printf(" Cocugu olan calisanlarin bakmakla yukumlu olduklari cocuk sayisinin ortalamasi:%.2f\n",ort_cocuk);
     printf(" Bakmakla yukumlu oldugu cocuk sayisi 3'ten fazla olan calisanlarin sayisi:%d\n",uc_cocuk);
     printf(" Engelli calisan sayisi:%d\n Engelli calisan yuzdesi: %.2f\n\n",engelli_calisan,yuzde_engelli);
//ÇALIŞANLARIN VERGİ ORANLARINA GÖRE AYRILMASI:
     printf("~~~ Vergi Oranlarina Gore Calisanlar ~~~\n\n");
     printf("\tYuzde 15 lik vergi icin\n Calisan sayisi: %d\n Yuzdesi: %.2f\n\n",vergi15,yuzde15);
     printf("\tYuzde 20 lik vergi icin\n Calisan sayisi: %d\n Yuzdesi: %.2f\n\n",vergi20,yuzde20);
     printf("\tYuzde 27 lik vergi icin\n Calisan sayisi: %d\n Yuzdesi: %.2f\n\n",vergi27,yuzde27);
     printf("\tYuzde 35 lik vergi icin\n Calisan sayisi: %d\n Yuzdesi: %.2f\n\n",vergi35,yuzde35);
//BRÜT ÜCRETİ EN YÜKSEK OLAN ÇALIŞAN BİLGİLERİ:
     printf("~~~ Toplam Brut Ucreti En Yuksek Olan Calisan ~~~\n\n");
     printf(" Tc No:%.0lf\n",eyb_tcno);
     printf(" Ad Soyad:");
     printf(eyb_isim);
     printf("\n");
     printf(" Aylik Brut Ucret:%.2f TL\n",enyuksek_brut);
     printf(" Gelir Vergisi Kesintisi:%.2f TL\n",eyb_vergi);
     printf(" Aylik Net Ucret:%.2f TL\n\n",eyb_net);
//NET ÜCRETİ EN YÜKSEK OLAN ÇALIŞAN BİLGİLERİ:
     printf("~~~ Toplam Net Ucreti En Yuksek Olan Calisan ~~~\n\n");
     printf(" Tc No:%.0lf\n",eyn_tcno);
     printf(" Ad Soyad:");
     printf(eyn_isim);
     printf("\n");
     printf(" Aylik Net Ucret:%.2f TL\n",enyuksek_net);
     printf(" Gelir Vergisi Kesintisi:%.2f TL\n",eyn_vergi);
     printf(" Aylik Brut Ucret:%.2f TL\n\n",eyn_brut);
//TOPLAM BANKNOT YAZDIRMA
     printf("~~~ Toplam Maas Icin Gerekli Banknotlar ~~~\n\n");
     if(tb200>0)
        printf("\t%d tane 200'luk\n",tb200);
     if(tb100>0)
        printf("\t%d tane 100'luk\n",tb100);
     if(tb50>0)
        printf("\t%d tane 50'luk\n",tb50);
     if(tb20>0)
        printf("\t%d tane 20'luk\n",tb20);
     if(tb10>0)
        printf("\t%d tane 10'luk\n",tb10);
     if(tb5>0)
        printf("\t%d tane 5'luk\n",tb5);
     if(tm100>0)
        printf("\t%d tane 1'lik\n",tm100);
     if(tm50>0)
        printf("\t%d tane 50 kurus\n",tm50);
     if(tm25>0)
        printf("\t%d tane 25 kurus\n",tm25);
     if(tm10>0)
        printf("\t%d tane 10 kurus\n",tm10);
     if(tm5>0)
        printf("\t%d tane 5 kurus\n",tm5);
     if(tm1>0)
       printf("\t%d tane 1 kurus\n",tm1);

  return 0;
    }
