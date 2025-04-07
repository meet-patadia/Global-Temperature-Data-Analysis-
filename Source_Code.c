//Authors: Hetvi Modi, Tanvi Jadhav, Meet Patadia
//Submission Date: April 2nd, 2024
//Description: CPS 188 TERM PROJECT WINTER 2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "GlobalTemperatures.csv"
#define START_YEAR 1760
#define END_YEAR 2015
#define NUM_MONTHS 12
#define NUM_COLUMNS 9
#define MAX_LINE_LENGTH 1000
#define NUM_YEARS (END_YEAR - START_YEAR + 1)
#define NUM_YEARS_19TH_CENTURY 50
#define NUM_YEARS_20TH_CENTURY 100
#define NUM_YEARS_21ST_CENTURY 15

// Structure to hold temperature data for each month
typedef struct {
    char dt[20]; // Date
    double land_avg_temp; // Land Average Temperature
} TemperatureData;

typedef struct {
    double avg_temp;
    double max_temp;
    double min_temp;
    int count;
} YearData;

// Function to calculate yearly averages
void calculateYearlyAverages(TemperatureData *data, int num_data_points) {
    double yearly_sums[END_YEAR - START_YEAR + 1] = {0};
    int yearly_counts[END_YEAR - START_YEAR + 1] = {0};

    for (int i = 0; i < num_data_points; i++) {
        int year = atoi(data[i].dt);
        if (year >= START_YEAR && year <= END_YEAR) {
            yearly_sums[year - START_YEAR] += data[i].land_avg_temp;
            yearly_counts[year - START_YEAR]++;
        }
    }

    printf("Year\tYearly Average Land Temperature\n");
    for (int year = START_YEAR; year <= END_YEAR; year++) {
        int index = year - START_YEAR;
        if (yearly_counts[index] > 0) {
            double yearly_avg = yearly_sums[index] / yearly_counts[index];
            printf("%d\t%.2f\n", year, yearly_avg);
        }
    }
}

// Function to calculate yearly averages
void calculateYearlyAverages1(TemperatureData *data, int num_data_points, double *yearly_averages) {
    double yearly_sums[END_YEAR - START_YEAR + 1] = {0};
    int yearly_counts[END_YEAR - START_YEAR + 1] = {0};

    for (int i = 0; i < num_data_points; i++) {
        int year = atoi(data[i].dt);
        if (year >= START_YEAR && year <= END_YEAR) {
            yearly_sums[year - START_YEAR] += data[i].land_avg_temp;
            yearly_counts[year - START_YEAR]++;
        }
    }

    for (int year = START_YEAR; year <= END_YEAR; year++) {
        int index = year - START_YEAR;
        if (yearly_counts[index] > 0) {
            yearly_averages[index] = yearly_sums[index] / yearly_counts[index];
        }
    }
}

// Function to calculate monthly averages
void calculateMonthlyAverages(float monthlyAverages[NUM_MONTHS], float landAverageTemperature[], int numRecords) {
    int monthCounts[NUM_MONTHS] = {0};
    memset(monthlyAverages, 0, sizeof(float) * NUM_MONTHS);

    for (int i = 0; i < numRecords; i++) {
        if (landAverageTemperature[i] != -999) { // Ignore missing values
            int month = (i % NUM_MONTHS);
            monthlyAverages[month] += landAverageTemperature[i];
            monthCounts[month]++;
        }
    }

    for (int i = 0; i < NUM_MONTHS; i++) {
        if (monthCounts[i] > 0) {
            monthlyAverages[i] /= monthCounts[i];
        }
    }
}

// Function to extract the month and year from the date string
void extractMonthYear(char *date, int *month, int *year) {
    sscanf(date, "%d-%d", year, month);
}


int main() {
    printf("Authors: Hetvi Modi, Tanvi Jadhav, Meet Patadia\n");
    printf("====================================\n\n");

    char buffer[2000];
    
    char *token;
    int temp1 = 0;
    double sum = 0;
    double average;
    double P1sum1 = 0;
    double P2sum1, P2sum2, P2sum3, P2sum4;
    double P1average1;
    double a[10];
    char line[1024];
    char LINE[1024];
    FILE *file = fopen(FILENAME, "r");
    FILE *input_file = fopen("GlobalTemperatures.csv", "r");
    FILE *output_file = fopen("yearly_averaged_data.txt", "w");
    FILE *input_file1 = fopen("GlobalTemperatures.csv", "r");
    FILE *output_file1 = fopen("monthly_averages.txt", "w");
    FILE *P11_input = fopen("GlobalTemperatures.csv", "r");
    FILE *P11_output = fopen("yearly_averaged_data.txt", "w");
    FILE *P9_output = fopen("temperature_averages.txt", "w");

    double hottestTemperature = -9999.0; // Initialize with a very low value
    double coldestTemperature = 9999.0; // Initialize with a very high value
    int hottestMonth = -1;
    int hottestYear = -1;
    int coldestMonth = -1;
    int coldestYear = -1;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    //Problem 1
    printf("\n====================================\n");
    printf("Problem 1:\n\n");
    // Skip header
    fgets(line, sizeof(line), file);
    // Read data
    int num_data_points = 0;
    TemperatureData data[5000]; // Assuming maximum of 5000 data points
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        int col = 0;
        TemperatureData temp;
        while (token != NULL && col < NUM_COLUMNS) {
            switch (col) {
                case 0:
                    strcpy(temp.dt, token);
                    break;
                case 1:
                    temp.land_avg_temp = atof(token);
                    break;
                default:
                    break;
            }
            token = strtok(NULL, ",");
            col++;
        }
        data[num_data_points++] = temp;
    }

    fclose(file);
    file = fopen(FILENAME,"r");
    // Calculate yearly averages
    calculateYearlyAverages(data, num_data_points);

    //Problem 2
    printf("\n====================================\n");
    printf("Problem 2:\n\n");
    P2sum1 = 0;
    P2sum2 = 0;
    P2sum3 = 0;
    P2sum4 = 0;
    while (temp1 <= 3192){ //The number of lines
    fgets(buffer, 2000, file);
    if(temp1>=121 && temp1<=600){
        for(int i1 = 0; i1<1; i1++){
            token = strtok(buffer, ",");
            token = strtok(NULL, ",");
            a[1] = atof(token);
            //printf("%lf \n",a[1]);
            P2sum1 = P2sum1 + a[1];
            }
        }
       if(temp1>=601 && temp1<=1800){
        for(int i1 = 0; i1<1; i1++){
            token = strtok(buffer, ",");
            token = strtok(NULL, ",");
            a[1] = atof(token);
            //printf("%lf \n",a[1]);
            P2sum2 = P2sum2 + a[1];
            }
        }
        if(temp1>=1801 && temp1<=3000){
        for(int i1 = 0; i1<1; i1++){
            token = strtok(buffer, ","); 
            token = strtok(NULL, ",");
            a[1] = atof(token);
            //printf("%lf \n",a[1]);
            P2sum3 = P2sum3 + a[1];
            }
        }
        if(temp1>=3001 && temp1<=3192){
        for(int i1 = 0; i1<1; i1++){
            token = strtok(buffer, ",");
            token = strtok(NULL, ",");
            a[1] = atof(token);
            //printf("%lf \n",a[1]);
            P2sum4 = P2sum4 + a[1];
            }
        }
        
        temp1++;
    }
    fclose(file);
   
    printf("The average land temperature in the 17th century was approximately %.2lf degrees\n", P2sum1/479);
    printf("The average land temperature in the 18th century was approximately %.2lf degrees\n", P2sum2/1199);
    printf("The average land temperature in the 19th century was approximately %.2lf degrees\n", P2sum3/1199);
    printf("The average land temperature in the 20th century upto 2015 was approximately %.2lf degrees\n", P2sum4/191); 
    
    //Problem 3
    printf("====================================\n");
    printf("Problem 3:\n\n");
    file = fopen(FILENAME,"r");
    char P3_line[MAX_LINE_LENGTH];
    int P3_year;
    float landAverageTemperature[MAX_LINE_LENGTH];
    int numRecords = 0;

    // Skip header line
    fgets(P3_line, MAX_LINE_LENGTH, file);

    // Read data
    while (fgets(P3_line, MAX_LINE_LENGTH, file)) {
        sscanf(P3_line, "%d-%*d-%*d,%f,", &P3_year, &landAverageTemperature[numRecords]);
        numRecords++;
    }

    fclose(file);

    // Calculate monthly averages for the specified P3_years
    float monthlyAverages[NUM_MONTHS];
    calculateMonthlyAverages(monthlyAverages, landAverageTemperature, numRecords);

    // Print monthly averages
    printf("Monthly Averages for P3_years 1900-2015:\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("Month %d: %.2f\n", i + 1, monthlyAverages[i]);
    }


    //Problem 4
    printf("====================================\n");
    printf("Problem 4:\n\n");
    file - fopen(FILENAME,"r");
    fgets(line, MAX_LINE_LENGTH, file);
    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char date[12]; // Date format is "YYYY-MM-DD"
        double temperature;
        sscanf(line, "%11[^,],%lf", date, &temperature);

        int month, year;
        extractMonthYear(date, &month, &year);

        if (temperature > hottestTemperature) {
            hottestTemperature = temperature;
            hottestMonth = month;
            hottestYear = year;
        }

        if (temperature < coldestTemperature) {
            coldestTemperature = temperature;
            coldestMonth = month;
            coldestYear = year;
        }
    }

    fclose(file);
    file = fopen(FILENAME,"r");
    // Print the result
    printf("The Hottest month was recorded on %d-%02d\n", hottestYear, hottestMonth);
    printf("The Coldest month was recorded on %d-%02d\n", coldestYear, coldestMonth);

    //Problem 5
    printf("====================================\n");
    printf("Problem 5:\n\n");
    // Skip header
    char line1[1024];
    fgets(line1, sizeof(line1), file);

    // Read data
    int num_data_points1 = 0;
    TemperatureData data1[5000]; // Assuming maximum of 5000 data points
    while (fgets(line1, sizeof(line1), file)) {
        char *token = strtok(line1, ",");
        int col = 0;
        TemperatureData temp;
        while (token != NULL && col < NUM_COLUMNS) {
            switch (col) {
                case 0:
                    strcpy(temp.dt, token);
                    break;
                case 1:
                    temp.land_avg_temp = atof(token);
                    break;
                default:
                    break;
            }
            token = strtok(NULL, ",");
            col++;
        }
        data1[num_data_points1++] = temp;
    }

    fclose(file);

    // Calculate yearly averages
    double yearly_averages[END_YEAR - START_YEAR + 1] = {0};
    calculateYearlyAverages1(data1, num_data_points1, yearly_averages);

    // Find hottest and coldest years
    double hottest_temp = yearly_averages[0];
    double coldest_temp = yearly_averages[0];
    int hottest_year = START_YEAR;
    int coldest_year = START_YEAR;
    for (int year = START_YEAR; year <= END_YEAR; year++) {
        int index = year - START_YEAR;
        if (yearly_averages[index] > hottest_temp) {
            hottest_temp = yearly_averages[index];
            hottest_year = year;
        }
        if (yearly_averages[index] < coldest_temp) {
            coldest_temp = yearly_averages[index];
            coldest_year = year;
        }
    }

    printf("The Hottest year was recorded on %d\n", hottest_year);
    printf("The Coldest year was recorded on %d\n", coldest_year);

    //Problem 6
    printf("====================================\n");
    printf("Problem 6:\n\n");

    // Arrays to store sum of temperatures and month count for each year
    double yearly_temp_sum[END_YEAR - START_YEAR + 1] = {0.0};
    int yearly_month_count[END_YEAR - START_YEAR + 1] = {0};

    // Skip the header line
    char header[100];
    fgets(header, sizeof(header), input_file);

    int year;
    double temperature;
    char LINE1[100];

    // Read each line in the input file
    while (fgets(LINE1, sizeof(LINE1), input_file) != NULL) {
        sscanf(LINE1, "%d-%*[^,],%lf", &year, &temperature);
        if (year >= START_YEAR && year <= END_YEAR) {
            int index = year - START_YEAR;
            yearly_temp_sum[index] += temperature;
            yearly_month_count[index]++;
        }
    }

    // Calculate and write the yearly average temperatures to the output file
    for (int i = 0; i < END_YEAR - START_YEAR + 1; i++) {
        if (yearly_month_count[i] > 0) {
            double avg_temperature = yearly_temp_sum[i] / yearly_month_count[i];
            fprintf(output_file, "%d %.2f\n", START_YEAR + i, avg_temperature);
        }
    }

    printf("Yearly averaged temperatures saved to 'yearly_averaged_data.txt'.\n");

    fclose(input_file);
    fclose(file);
    fclose(output_file);

    //Problem 7
    printf("====================================\n");
    printf("Problem 7:\n\n");
    file = fopen(FILENAME,"r");
    char P7_line[1000];
    double yearlySum1800to1899[100] = {0};
    double yearlySum1900to1999[100] = {0};
    int count1800to1899[100] = {0};
    int count1900to1999[100] = {0};

    // Skip the header P7_line
    fgets(P7_line, 1000, file);

    // Read data from the CSV file and calculate averages
    while (fgets(P7_line, 1000, file) != NULL) {
        int year;
        double temperature;
        sscanf(P7_line, "%d-%*[^,],%f", &year, &temperature);

        if (year >= 1800 && year <= 1899) {
            yearlySum1800to1899[year - 1800] += temperature;
            count1800to1899[year - 1800]++;
        } else if (year >= 1900 && year <= 1999) {
            yearlySum1900to1999[year - 1900] += temperature;
            count1900to1999[year - 1900]++;
        }
    }

    fclose(file);

    // Write averages to a new file
    FILE *P7_output = fopen("yearly_averages.dat", "w");
    if (P7_output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    //fprintf(P7_output, "Year\t1800-1899 Avg\t1900-1999 Avg\n");
    for (int i = 0; i < 100; i++) {
        double avg1800to1899 = (count1800to1899[i] != 0) ? yearlySum1800to1899[i] / count1800to1899[i] : 0;
        double avg1900to1999 = (count1900to1999[i] != 0) ? yearlySum1900to1999[i] / count1900to1999[i] : 0;
        fprintf(P7_output, "%d\t%.2f\t%.2f\n", i + 1, avg1800to1899, avg1900to1999);
    }

    fclose(P7_output);

    printf("Yearly averages have been written to 'yearly_averages.dat' successfully.\n");

     //Problem 8
    printf("====================================\n");
    printf("Problem 8:\n\n");
    file = fopen(FILENAME,"r");
    YearData year_data[NUM_YEARS] = {0};

    // Skip header
    char line2[100];
    fgets(line2, sizeof(line2), file);

    // Read data from file
    while (fgets(line2, sizeof(line2), file)) {
        int year;
        double avg_temp, max_temp, min_temp;
        sscanf(line2, "%d-%*d-%*d,%lf,%*lf,%lf,%*lf,%lf,%*lf", &year, &avg_temp, &max_temp, &min_temp);
        if (year >= START_YEAR && year <= END_YEAR) {
            year_data[year - START_YEAR].avg_temp += avg_temp;
            year_data[year - START_YEAR].max_temp += max_temp;
            year_data[year - START_YEAR].min_temp += min_temp;
            year_data[year - START_YEAR].count++;
        }
    }

    fclose(file);

    // Calculate yearly averages
    for (int i = 0; i < NUM_YEARS; i++) {
        if (year_data[i].count > 0) {
            year_data[i].avg_temp /= year_data[i].count;
            year_data[i].max_temp /= year_data[i].count;
            year_data[i].min_temp /= year_data[i].count;
        }
    }

    // Write data to GNUPlot file
    FILE *gnuplot_file = fopen("temp_plot_data.txt", "w");
    if (gnuplot_file == NULL) {
        perror("Error opening GNUPlot file");
        return 1;
    }
    for (int i = 0; i < NUM_YEARS; i++) {
        fprintf(gnuplot_file, "%d %.3lf %.3lf %.3lf\n", START_YEAR + i,
                year_data[i].avg_temp, year_data[i].max_temp, year_data[i].min_temp);
    }
    
    printf("All values saved to 'yearly_averages.dat'\n");
    fclose(gnuplot_file);

    //Problem 9
    printf("====================================\n");
    printf("Problem 9:\n\n");

    // Variables to store sum of temperatures for each century
    double sum_avg_temp_19th = 0, sum_max_temp_19th = 0, sum_min_temp_19th = 0;
    double sum_avg_temp_20th = 0, sum_max_temp_20th = 0, sum_min_temp_20th = 0;
    double sum_avg_temp_21st = 0, sum_max_temp_21st = 0, sum_min_temp_21st = 0;

    // Variables to store temperature data
    int P9_year;
    double avg_temp, max_temp, min_temp;
    char P9_line[100];

    // Read and process each P9_line in the file
    while (fgets(P9_line, sizeof(P9_line), file) != NULL) {
        sscanf(P9_line, "%d,%lf,%lf,%lf", &P9_year, &avg_temp, &max_temp, &min_temp);

        // Check which century the year belongs to and update the sum accordingly
        if (P9_year >= 1850 && P9_year <= 1899) {
            sum_avg_temp_19th += avg_temp;
            sum_max_temp_19th += max_temp;
            sum_min_temp_19th += min_temp;
        } else if (P9_year >= 1900 && P9_year <= 1999) {
            sum_avg_temp_20th += avg_temp;
            sum_max_temp_20th += max_temp;
            sum_min_temp_20th += min_temp;
        } else if (P9_year >= 2000 && P9_year <= 2015) {
            sum_avg_temp_21st += avg_temp;
            sum_max_temp_21st += max_temp;
            sum_min_temp_21st += min_temp;
        }
    }

    // Calculate the averages
    double avg_avg_temp_19th = sum_avg_temp_19th / NUM_YEARS_19TH_CENTURY;
    double avg_max_temp_19th = sum_max_temp_19th / NUM_YEARS_19TH_CENTURY;
    double avg_min_temp_19th = sum_min_temp_19th / NUM_YEARS_19TH_CENTURY;

    double avg_avg_temp_20th = sum_avg_temp_20th / NUM_YEARS_20TH_CENTURY;
    double avg_max_temp_20th = sum_max_temp_20th / NUM_YEARS_20TH_CENTURY;
    double avg_min_temp_20th = sum_min_temp_20th / NUM_YEARS_20TH_CENTURY;

    double avg_avg_temp_21st = sum_avg_temp_21st / NUM_YEARS_21ST_CENTURY;
    double avg_max_temp_21st = sum_max_temp_21st / NUM_YEARS_21ST_CENTURY;
    double avg_min_temp_21st = sum_min_temp_21st / NUM_YEARS_21ST_CENTURY;

    // Print the results to the output file
    fprintf(P9_output, "Century\tAverage Land Temperature\tAverage Max Temperature\tAverage Min Temperature\n");
    fprintf(P9_output, "19th\t%.2f\t%.2f\t%.2f\n", avg_avg_temp_19th, avg_max_temp_19th, avg_min_temp_19th);
    fprintf(P9_output, "20th\t%.2f\t%.2f\t%.2f\n", avg_avg_temp_20th, avg_max_temp_20th, avg_min_temp_20th);
    fprintf(P9_output, "21st\t%.2f\t%.2f\t%.2f\n", avg_avg_temp_21st, avg_max_temp_21st, avg_min_temp_21st);
    printf("All the values are saved to 'temperature_averages.txt'\n");

    fclose(file);
    fclose(P9_output);

    //Problem 10
    printf("====================================\n");
    printf("Problem 10:\n\n");
    // Initialize arrays to store sum and count for each month
    double sum_temp[NUM_MONTHS] = {0};
    int count[NUM_MONTHS] = {0};

    int P10_year, month;
    double P10_temperature;
    char LINE3[100];

    // Read each LINE3 in the input file
    while (fgets(LINE3, sizeof(LINE3), input_file1) != NULL) {
        sscanf(LINE3, "%d-%*[^,],%lf", &P10_year, &P10_temperature);

        // Check if the year is within the specified range
        if (P10_year >= 2000 && P10_year <= 2015) {
            // Extract the month from the date
            sscanf(LINE3, "%d-%d-%*[^,]", &P10_year, &month);

            // Accumulate temperature for each month
            sum_temp[month - 1] += P10_temperature;
            count[month - 1]++;
        }
    }

    // Write the monthly average temperatures to the output file
    fprintf(output_file1, "Month\tAverage Temperature\n");
    for (int i = 0; i < NUM_MONTHS; i++) {
        double avg_temp = count[i] > 0 ? sum_temp[i] / count[i] : 0;
        fprintf(output_file1, "%d\t%.2lf\n", i + 1, avg_temp);
    }

    printf("Monthly average temperatures for the years 2000 to 2015 have been saved to 'monthly_averages.txt'.\n");

    fclose(input_file1);
    fclose(output_file1);
    
    //Problem 11
    printf("====================================\n");
    printf("Problem 11:\n\n");
    
    int P11_year;
    double second_col_value, seventh_col_value;
    double yearly_second_col_sum[2015 - 1850 + 1] = {0};
    double yearly_seventh_col_sum[2015 - 1850 + 1] = {0};
    int P11_yearly_mountCount[2015 - 1850 + 1] = {0};

    char P11_line[100];

    // Skip the header line
    fgets(P11_line, sizeof(P11_line), P11_input);

    // Read each line in the input file
    while (fgets(P11_line, sizeof(P11_line), P11_input) != NULL) {
        sscanf(P11_line, "%d-%*[^,],%lf,%*lf,%*lf,%*lf,%*lf,%lf", &P11_year, &second_col_value, &seventh_col_value);
        if (P11_year >= 1850 && P11_year <= 2015) {
            int index = P11_year - 1850;
            yearly_second_col_sum[index] += second_col_value;
            yearly_seventh_col_sum[index] += seventh_col_value;
            P11_yearly_mountCount[index]++;
        }
    }

    // Calculate and write the yearly average second and seventh column values to the output file
    for (int i = 0; i < 2015 - 1850 + 1; i++) {
        if (P11_yearly_mountCount[i] > 0) {
            double avg_second_col = yearly_second_col_sum[i] / P11_yearly_mountCount[i];
            double avg_seventh_col = yearly_seventh_col_sum[i] / P11_yearly_mountCount[i];
            fprintf(P11_output, "%d %.2f %.2f\n", 1850 + i, avg_second_col, avg_seventh_col);
        }
    }

    printf("Yearly averaged second and seventh column data saved to 'yearly_averaged_data.txt'.\n");

    fclose(P11_input);
    fclose(P11_output);

     printf("====================================\n");
     printf("End of Program");


    return 0;
}
