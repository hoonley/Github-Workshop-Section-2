# Student: Shakif Hossain
# Programming Exercise: 2_1

import InputBox
InputBox.ShowDialog("How much do you weight in pounds?")
lbs = InputBox.GetInput()
kg = (float(lbs) *  0.45359237)

s = "Results:\n"

s += "You Weigh " + str(kg) + "kg."

import MessageBox
MessageBox.Show(s)