// Optional lab: half
// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <stdio.h>
#include <cs50.h>

// Unassigned declarations
float half(float bill, float tax, int tip);
float compute_sales_tax(float bill, float tax);
float compute_sub_total(float tax, float bill);
float compute_tip(float sub, float rate);
float compute_grand_total(float sub, float tip);
float compute_amount_owed(float total);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float sales_tax = compute_sales_tax(bill, tax);
    float sub_total = compute_sub_total(sales_tax, bill);
    float calculated_tip = compute_tip(sub_total, tip);
    float grand_total = compute_grand_total(sub_total, calculated_tip);
    float your_half = compute_amount_owed(grand_total);
    return your_half;
}

// TODO: Calculate salestax
float compute_sales_tax(float bill, float tax)
{
    float applied_tax = (float)bill * ((float)tax * .01);
    return applied_tax;
}

// TODO: Calculate subtotal
float compute_sub_total(float tax, float bill)
{
    float sub = (float)tax + (float)bill;
    return sub;
}

// TODO: Calculate tip
float compute_tip(float sub, float rate)
{
    float gratuity = (float)sub * ((float)rate * .01);
    return gratuity;
}

// TODO: Calculate grandtotal
float compute_grand_total(float sub, float tip)
{
    float total = (float)sub + (float)tip;
    return total;
}

// TODO: Calculate final return amount
float compute_amount_owed(float total)
{
    float your_half = (float)total / 2;
    return your_half;
}