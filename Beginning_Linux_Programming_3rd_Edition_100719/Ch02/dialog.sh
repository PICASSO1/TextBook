#!/bin/bash

# Ask some questions and colloct the answer.

dialog --title "Questionnaire" --msgbox "Welcome to my simple survey" 9 18

dialog --title "Confirm" --yesno "Are you willing to take part?? " 9 18

if [ $? != 0 ]; then
	dialog --infobox "Thank you anyway!! " 5 20
	sleep 2
	dialog --clear
fi

exit 0
