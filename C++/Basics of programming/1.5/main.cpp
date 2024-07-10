#include "reference.cpp"
int main()
{
    float input;
    cin >> input;
    float &reference_input=input;
    reference(reference_input);
}