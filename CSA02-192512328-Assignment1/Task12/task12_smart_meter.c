#include <stdio.h>
#include <stdlib.h>

#define TARIFF_FILE "tariff.txt"
#define READINGS_FILE "readings.txt"
#define PEAK_START 18
#define PEAK_END 22

int main(void)
{
    FILE *fp;
    double rate = 0.0, multiplier = 0.0;
    long long normalWh = 0, peakWh = 0;
    long long energy;
    int hour, count = 0;
    char line[100];
    int hasRate = 0, hasMultiplier = 0;

    /* Read tariff configuration */
    fp = fopen(TARIFF_FILE, "r");

    if (fp == NULL) {
        perror("Cannot open tariff.txt");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, " normal_rate = %lf", &rate) == 1) {
            hasRate = 1;
        } else if (sscanf(line, " peak_multiplier = %lf",
                          &multiplier) == 1) {
            hasMultiplier = 1;
        }
    }

    fclose(fp);

    if (!hasRate || !hasMultiplier ||
        rate <= 0 || multiplier < 1.0) {
        printf("Invalid tariff configuration.\n");
        return 1;
    }

    /* Read smart-meter readings */
    fp = fopen(READINGS_FILE, "r");

    if (fp == NULL) {
        perror("Cannot open readings.txt");
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (sscanf(line, "%d %lld", &hour, &energy) != 2) {
            printf("Invalid reading: %s", line);
            fclose(fp);
            return 1;
        }

        if (hour < 0 || hour > 23 || energy < 0) {
            printf("Invalid hour or energy reading.\n");
            fclose(fp);
            return 1;
        }

        if (hour >= PEAK_START && hour < PEAK_END) {
            peakWh += energy;
        } else {
            normalWh += energy;
        }

        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No meter readings found.\n");
        return 1;
    }

    /* Convert Wh to kWh and calculate charges */
    double normalKWh = normalWh / 1000.0;
    double peakKWh = peakWh / 1000.0;

    long long normalPaise =
        (long long)(normalKWh * rate * 100 + 0.5);

    long long peakPaise =
        (long long)(peakKWh * rate * multiplier * 100 + 0.5);

    long long totalPaise = normalPaise + peakPaise;

    /* Display bill */
    printf("\n===== ELECTRICITY BILL =====\n");
    printf("Normal tariff: Rs. %.2f per kWh\n", rate);
    printf("Peak multiplier: %.2f\n", multiplier);
    printf("Peak hours: 6 PM to 10 PM\n");
    printf("Readings processed: %d\n", count);

    printf("\nNormal energy: %.3f kWh\n", normalKWh);
    printf("Peak energy: %.3f kWh\n", peakKWh);

    printf("Normal charge: Rs. %lld.%02lld\n",
           normalPaise / 100, normalPaise % 100);

    printf("Peak charge: Rs. %lld.%02lld\n",
           peakPaise / 100, peakPaise % 100);

    printf("----------------------------\n");
    printf("TOTAL BILL: Rs. %lld.%02lld\n",
           totalPaise / 100, totalPaise % 100);
    printf("============================\n");

    return 0;
}

