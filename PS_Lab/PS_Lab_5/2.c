#include <stdio.h>
#define OVERTIME_RATE 1.5
#define TAX_DEDUCTION 0.03625
#define WEEKLY_MIN_HOURS 40
int main() {
  FILE *in, *out;
  in = fopen("./in.txt", "r"); // ID hourly_rate hours
  out = fopen("./out.txt", "w");
  int id, input_status, count = 0;
  float hourly_rate, hours, overtime_hours, payroll, total_payroll;
  if (in == NULL) {
    printf("in.txt does not exist");
    return 0;
  }
  if (out == NULL) {
    printf("out.txt does not exist");
    return 0;
  }
  fscanf(in, "%d %f %f", &id, &hourly_rate, &hours);
  printf("   Employee ID   Net Payroll\n");
  while (!feof(in)) {
    overtime_hours = payroll - WEEKLY_MIN_HOURS;
    if (overtime_hours > 40)
      payroll = 40 * hourly_rate + overtime_hours * hourly_rate * OVERTIME_RATE;
    else
      payroll = hours * hourly_rate;
    payroll -= payroll * TAX_DEDUCTION;
    printf("%14d%14.2f\n", id, payroll);
    count++;
    total_payroll += payroll;
    fscanf(in, "%d %f %f", &id, &hourly_rate, &hours);
  }
  fprintf(out, "Average payroll: %.2f", total_payroll / count);
  return 0;
}