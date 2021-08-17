/*File that includes calculations of electrical power of electricity system components, considering Energy Efficiency Ruling for Buildings in Greece (K.En.A.K)*/
/* KKM= Central AirConditioner Unit*/ 

#include <stdio.h>

int main()
{
    int choice;
    double result;
    
    printf("1: Electrical Power FCU/VRV\n2: Electrical Power Circulator\n");
    printf("3: Electrical Power of Simple Fan/Exchanger\n4: Electrical Power KKM without Exchanger\n");
    printf("5: Electrical Power KKM with Exchanger:\n6: Electrical Power boiler\n");
    scanf("%d", &choice);
    
    if(choice ==  1){
        double room_load = 1;
        while(room_load != 0){
            printf("Give cooling/thermal load of room in W: ");
            scanf("%lf", &room_load);
        
            result = (room_load / 6) * 0.000265;
            printf("Electrical Power of fan FCU/VRV in KW: %lf  KW\n", result);
        }
    }
    else if(choice == 2){
        double power_of_cooling_or_heating_load_in_kcalperhour = 0;
        double power_of_cooling_or_heating_in_W = 0;
        double supply_in_litres_per_hour = 0;
        double supply_in_litres_per_second = 0;
        int dt = 0;
        double manometer_height_in_MYS = 0;
        
        printf("Give power of cooling or heating load of circulator in W: ");
        scanf("%lf", &power_of_cooling_or_heating_in_W);
        
        printf("Give DT in Celsium degrees (5(cooling) h 15 (boiler)): ");
        scanf("%d", &dt);
        
        power_of_cooling_or_heating_load_in_kcalperhour = power_of_cooling_or_heating_in_W / 1.163;
        supply_in_litres_per_hour = power_of_cooling_or_heating_load_in_kcalperhour / dt;
        supply_in_litres_per_second = supply_in_litres_per_hour / 3600;
        
        if(power_of_cooling_or_heating_load_in_kcalperhour < 45000){
            manometer_height_in_MYS = (3 * power_of_cooling_or_heating_load_in_kcalperhour) / 45000;
            if(manometer_height_in_MYS < 0.6){
                manometer_height_in_MYS = 0.6;
            }
            if(manometer_height_in_MYS > 3.0){
                manometer_height_in_MYS = 3.0;
            }
        }
        else if((power_of_cooling_or_heating_load_in_kcalperhour >= 45000) && (power_of_cooling_or_heating_load_in_kcalperhour <= 85000)){
            manometer_height_in_MYS = (5 * power_of_cooling_or_heating_load_in_kcalperhour) / 85000;
            if(manometer_height_in_MYS< 3.0){
                manometer_height_in_MYS = 3.0;
            }
            if(manometer_height_in_MYS > 5.0){
                manometer_height_in_MYS = 5.0;
            }
        }
        else if(power_of_cooling_or_heating_load_in_kcalperhour > 85000){
            manometer_height_in_MYS = (5 * power_of_cooling_or_heating_load_in_kcalperhour) / 85000;
            if(manometer_height_in_MYS < 5.0){
                manometer_height_in_MYS = 5.0;
            }
            if(manometer_height_in_MYS > 10.0){
                manometer_height_in_MYS = 10.0;
            }
        }
        
        result = (supply_in_litres_per_second * 10 * manometer_height_in_MYS) / (1020 * 0.6);
        printf("Electrical Power of circulator in KW: %lf  KW", result);
    }
    else if(choice == 3){
        double air_supply_in_m3_per_hour = 0;
        double air_supply_in_m3_per_sec = 0;
        
        printf("Give total air supply of simple fan in m^3/h: ");
        scanf("%lf", &air_supply_in_m3_per_hour);
        
        air_supply_in_m3_per_sec = air_supply_in_m3_per_hour / 3600;
        
        result = air_supply_in_m3_per_sec * 1.0;
        printf("Electrical power of simple fan in KW: %lf", result);
    }
    else if(choice == 4){
        double air_supply_in_m3_per_hour = 0;
        double air_supply_in_m3_per_sec = 0;
        
        printf("Give total air supply of KKM without exchanger in m^3/h: ");
        scanf("%lf", &air_supply_in_m3_per_hour);
        
        air_supply_in_m3_per_sec = air_supply_in_m3_per_hour / 3600;
        
        result = air_supply_in_m3_per_sec * 1.5;
        printf("Electrical power of KKM without exchanger in KW (for one of the 2 fans): %lf", result);
    }
    else if(choice == 5){
        double air_supply_in_m3_per_hour = 0;
        double air_supply_in_m3_per_sec = 0;
        
        printf("Give total air supply of KKM with exchanger in m^3/h: ");
        scanf("%lf", &air_supply_in_m3_per_hour);
        
        air_supply_in_m3_per_sec = air_supply_in_m3_per_hour / 3600;
        
        result = air_supply_in_m3_per_sec * 2.5;
        printf("Electrical power of KKM with exchanger in KW (for one of the 2 fans): %lf", result);
    }
    else if(choice == 6){
        double total_thermal_load = 0;
        
        printf("Give total thermal load in W: ");
        scanf("%lf", &total_thermal_load);
        
        result = total_thermal_load * 0.015;
        printf("Electrical power of boiler in W: %lf", result);
    }
    
    return 0;
}
