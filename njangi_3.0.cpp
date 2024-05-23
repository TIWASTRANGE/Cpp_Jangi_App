#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Loan {
private:
    double amount;
    double interestRate;
    int monthsRemaining;

public:
    void setAmount(double amount) {
        this->amount = amount;
    }

    double getAmount() {
        return amount;
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() {
        return interestRate;
    }

    void setMonthsRemaining(int months) {
        monthsRemaining = months;
    }

    int getMonthsRemaining() {
        return monthsRemaining;
    }
};

class Contribution{
	private:
		string TypeOfContribution;
		double Amount;

	public:
		void setTypeOfContribution(string Type){
			this->TypeOfContribution = Type;
		}

		string getType(){
			return TypeOfContribution;
		}

		void setAmount(double amount){
			this->Amount = amount;
		}

		double getAmount(){
			return Amount;
		}
};

class Member {
private:
    string name;
    vector<Contribution*> contributions;
    double savings;
    vector<Loan*> loans;
    double Payment;
    int BallotNumber;

public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

   void addContribution(Contribution* contribution) {
        contributions.push_back(contribution);
   }

   Contribution* getContibution(int index){
       if(index >= 0 && index < contributions.size()){
        return contributions[index];
       }
       return 0;
   }
   
   int getcontributionCount(){
   	return contributions.size();
   }
   
   

    void setSavings(double amount) {
        savings = amount;
    }

    double getSavings() {
        return savings;
    }

    void addLoan(Loan* loan) {
        loans.push_back(loan);
    }

    void removeLoan(Loan* loan) {
        loans.erase(remove(loans.begin(), loans.end(), loan), loans.end());
    }

    int getLoansCount() {
        return loans.size();
    }

    Loan* getLoan(int index) {
        if (index >= 0 && index < loans.size()) {
            return loans[index];
        }
        return 0;
    }

    void setPayment(double payment){
    	this->Payment = payment;
	}
	
	double getPayment(){
		return Payment;
	}
	
	void setBallotNUmber(int ballotnumber){
		this->BallotNumber = ballotnumber;
	}
	
	int getBallotNumber(){
		return BallotNumber;
	}
};

class Bureau {
private:
	 string president;
    string secretaryGeneral;
    string assistantSecretary;
    string financialSecretary;
    string treasurer;
    string socials;

    vector <Member*> bureaus;


public:
	  void setPresident(string name) {
        president = name;
    }

    string getPresident() {
        return president;
    }

    void setSecretaryGeneral(string name) {
        secretaryGeneral = name;
    }

    string getSecretaryGeneral() {
        return secretaryGeneral;
    }

    void setAssistantSecretary(string name) {
        assistantSecretary = name;
    }

    string getAssistantSecretary() {
        return assistantSecretary;
    }

    void setFinancialSecretary(string name) {
        financialSecretary = name;
    }

    string getFinancialSecretary() {
        return financialSecretary;
    }

    void setTreasurer(string name) {
        treasurer = name;
    }

    string getTreasurer() {
        return treasurer;
    }

    void setSocials(string name) {
        socials = name;
    }

    string getSocials() {
        return socials;
    }
	
    void addBureau(Member* member) {
        bureaus.push_back(member);
    }


};

class Jangi {
private:
	double RegistrationFee;
    vector<Member*> members;
    Bureau bureau;

public:
    void setRegistrationFee(double fee) {
       this->RegistrationFee = fee;
    }

    double getRegistrationFee(){
    	return RegistrationFee;
	}


    void addMember(Member* member) {
        members.push_back(member);
    }

    void removeMember(Member* member) {
        members.erase(
            remove(members.begin(), members.end(), member),
            members.end()
        );
    }

    int getMembersCount () {
        return members.size();
    }

    Member* getMember(int index) {
        if (index >= 0 && index < members.size()) {
            return members[index];
        }
        return 0;
    }

    Bureau getBureau() {
        return bureau;
    }

     int Balloting() {
        return ((rand()% getMembersCount()) + 1);

    }
};


void displayMenu() {
    cout << "-------------------------" <<endl;
    cout << "1. Add Member" <<endl;
    cout << "2. Perform Balloting" <<endl;
    cout << "3. Add The Jangi Bureau Members" <<endl;
    cout << "4. Make Monthly Payment" <<endl;
    cout << "5. Make a Social Contribution" <<endl;
    cout << "6. Make Savings" <<endl;
    cout << "7. Take a Loan" <<endl;
    cout << "8. Display Members and Totals" <<endl;
    cout << "9. Display Bureau Members"<<endl;
    cout << "10. Remove Member" <<endl;
    cout << "11. Exit" <<endl;
    cout << "-------------------------" <<endl;
    cout << "Enter your choice: ";
}
// Display Members Function
 void displayMembers( Jangi jangi) {
    cout << "Members:" <<endl;
    int i;
    // Iterate Through the list of existing members and Display Each Member and Features
    for ( i = 0; i < jangi.getMembersCount(); i++) {
        Member* member = jangi.getMember(i);
        // Dispay Member Name
        cout << "Member " << (i + 1) << ": " << member->getName() <<endl;
        
        cout << "Ballot Number: "<< member->getBallotNumber() <<endl;
        
        // Display Member Payment
        cout << "Total Payments: " << member->getPayment()<<"XAF"<<endl;
        //Display Member Savings
        cout << "Savings: " << member->getSavings() <<"XAF"<<endl;
        
        // Iterate Through the Contribution List and For each Member, Display their Contribution and Type
        int contributionCount = member->getcontributionCount();
        double totalContribution;
        for(int j = 0; j< contributionCount; j++){
        	Contribution* contribution = member->getContibution(j);
        	totalContribution = contribution->getAmount();
        			
		cout<< "Contribution: " << totalContribution <<endl;
		cout<< "Contribution Type: "<< contribution->getType()<<endl;
		}

        int loansCount = member->getLoansCount();
        double totalLoanAmount = 0.0;
        for (int k = 0; k < loansCount; k++) {
            Loan* loan = member->getLoan(k);
            totalLoanAmount += loan->getAmount();
        }

        cout << "Total Loan Amount: " << totalLoanAmount << endl << endl;
    }
}


//Here's the `main` function that incorporates the interactive menu:

int main()
{
    Jangi  jangi;
    Bureau bureau;
    double registrationAmount;
    cout << "*********************************************"<<endl;
    cout << "    WELCOME TO GROUP 10 JANGI APP SYSTEM    "<<endl;
    cout << "*********************************************"<<endl<<endl;
    cout << "Please Enter The Jangi App Member Registration Fee: ";
    cin >> registrationAmount;
    jangi.setRegistrationFee(registrationAmount);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore any remaining characters in the input buffer

        switch (choice) {
            case 1: {
                // Add Member
                string name;
                double regfee;

                cout << "Enter member name: ";
                getline(cin, name);

                do{
                   cout << "Enter New Member Registration Fee of "<< jangi.getRegistrationFee() << "XAF: ";
                   cin >> regfee;
                if(jangi.getRegistrationFee() != regfee){
                	cout<<"The amount you entered is not the required amount for Registration"<<endl;
				}
            }
            while(jangi.getRegistrationFee() != regfee);

                Member* member = new Member();
                member->setName(name);

                jangi.addMember(member);

                cout <<member->getName() <<" has been added successfully to the Jangi system!" << endl;
                break;
            }
            
            case 2:{
            // Perform Ballot
            	int i;
            	Member* member = new Member();
            	if(jangi.getMembersCount() < 2){
            		cout << "There Members are not sufficient to Perform Balloting" <<endl;
				}
				else {
					for(i = 0; i < jangi.getMembersCount(); i++){
						int randomValue = jangi.Balloting();
						jangi.getMember(i)->setBallotNUmber(randomValue);
						
					}
					cout << "Random Ballot Number Has been Made Successfully!"<<endl;
				}
            	
				break;
			}
			
			
			case 3: {
			// Adding the Bureau Members
				int index1;
				int index2;
				int index3;
				int index4;
				int index5;
				int index6;
				cout<< "Enter Index of Member to Be the Jangi President: ";
				cin>> index1;
				Member* member1 = jangi.getMember(index1);
			// Adding The President	
				if((jangi.getMembersCount() - 1) < index1){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member1);
					cout<< "The President is "<<member1->getName() <<endl;
					bureau.setPresident(member1->getName());
				}
				
		    // Adding the Secretary General
		    cout<< "Enter Index of Member to Be the Jangi Secretary General: ";
			cin>> index2;
			Member* member2 = jangi.getMember(index2);
		    		if((jangi.getMembersCount() - 1) < index2){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member2); 
					cout<< "The Secretary General is: "<<member2->getName() <<endl;
					bureau.setSecretaryGeneral(member2->getName());
				}
				
			// Adding The Assistant Secretary
			cout<< "Enter Index of Member to Be the Jangi Assistant Secretary: ";
			cin>> index3;
			Member* member3 = jangi.getMember(index3);
					if((jangi.getMembersCount() - 1) < index3){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member3);
					cout<< "The Assistant Secretary is: "<<member3->getName() <<endl;
					bureau.setAssistantSecretary(member3->getName());
				}
				
			// Adding the Financial secretary
			cout<< "Enter Index of Member to Be the Jangi Financial Secretary: ";
			cin>> index4;
			Member* member4 = jangi.getMember(index4);
					if((jangi.getMembersCount() - 1) < index4){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member4);
					cout<< "The Financial Secretary is: "<<member4->getName() <<endl;
					bureau.setFinancialSecretary(member4->getName());
				}
				
			// Adding The Treasurer
			cout<< "Enter Index of Member to Be the Jangi Treasurer: ";
			cin>> index5;
			Member* member5 = jangi.getMember(index5);
					if((jangi.getMembersCount() - 1) < index5){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member5);
					cout<< "The Treasurer is: "<<member5->getName() <<endl;
					bureau.setTreasurer(member5->getName());
				}
				
			// Adding The Socials
			cout<< "Enter Index of Member to Be the Jangi Socials: ";
			cin>> index6;
			Member* member6 = jangi.getMember(index6);
				if((jangi.getMembersCount() - 1) < index6){
					cout<< "The Member does not Exist"<<endl;
				}
				else{
					bureau.addBureau(member6);
					cout<< "The Socials is: "<<member6->getName() <<endl;
					bureau.setSocials(member6->getName());
				}
				
				break;
			}
            
            case 4: {
                // Make Monthly Payment
                int index;
                double paymentAmount;
                
                cout << "Enter the payment amount: ";
                cin >> paymentAmount;

                cout << "Enter the index of the member: ";
                cin >> index;

                Member* member = jangi.getMember(index);
                if (member != 0) {
                    double newPayment = member->getPayment() + paymentAmount;

                        member->setPayment(newPayment);
                        cout << "Payment made successfully!" << endl;

                }
				else {
                    cout << "Sorry! The Member does not exist." << endl;
                }
                break;
            }
            
            case 5: {
            	//Making a Social Contribution
            	int index;
            	double ContributionAmount;
            	string ContributionType;
            	
            	cout<< "Please Enter The Type of Social Contribution: ";
            	getline(cin, ContributionType);

            	cout<< "Enter The Amount To Be Contributed: ";
            	cin>> ContributionAmount;


            	cout<< "Enter The Index of The Member Making The Contribution: ";
            	cin>> index;

            	Member* member = jangi.getMember(index);
            	if(member != 0){
                        Contribution* contribution = new Contribution();
                        contribution->setAmount(ContributionAmount);
                        contribution->setTypeOfContribution(ContributionType);

                        member->addContribution(contribution);
                    cout<< jangi.getMember(index)->getName() << " has Made a Contribution of "<< contribution->getAmount() << "XAF for a members ";
					cout<< contribution->getType() <<endl;
            	}
            	else{
            	    cout<< "Sorry! The Member does not exist"<<endl;
            	}

            	break;
            }
            
                case 6: {
                int index;
                cout << "Enter the index of the member to make savings: ";
                cin >> index;
                Member* member = jangi.getMember(index);
                if (member != 0) {
                    double amount;
                    cout << "Enter the savings amount: ";
                    cin >> amount;
                    double savings = member->getSavings();
                    member->setSavings(savings + amount);
                    cout << "Savings made successfully!" << endl;
                } else {
                    cout << "Invalid member index!" << endl;
                }
                break;
            }
            
            case 7: {
                // Take a Loan
                int index;
                double loanAmount;

                cout << "Enter the loan amount: ";
                cin >> loanAmount;

                cout << "Enter the index of the member taking the loan: ";
                cin >> index;

                Member* member = jangi.getMember(index);
                if (member != 0) {
                    Loan* loan = new Loan();
                    loan->setAmount(loanAmount);

                    member->addLoan(loan);
                    cout <<jangi.getMember(index)->getName()<< " has taken a Loan of " <<loan->getAmount() <<" successfully!" << endl;
                } else {
                    cout << "Sorry! The Member does not exist." << endl;
                }
                break;
            }
            
          case 8:
                // Display Members and Totals
              displayMembers(jangi);
               break;
               
               case 9: {
               	//Dispaly Bureau members
               	
               	cout<< "BUREAU MEMBERS IN THE GROUP 10 JANGI ARE"<<endl<<endl;
               	cout<< "1. President: "<<bureau.getPresident()<<endl;
               	cout<< "2. Secretary General: "<< bureau.getSecretaryGeneral()<<endl;
               	cout<< "3. Assistant Secretary: "<< bureau.getAssistantSecretary()<<endl;
               	cout<< "4. Financial Secretary: "<<bureau.getFinancialSecretary()<<endl;
               	cout<< "5. Treasurer: "<< bureau.getTreasurer()<<endl;
               	cout<< "6. Socials: "<< bureau.getSocials()<<endl;
               	
               	
				break;
			   }
               
                   
            case 10: {
                // Remove Member
                int index;
                string deleteMember;
                string response;

                cout << "Enter the index of the member to remove: ";
                cin >> index;

                Member* member = jangi.getMember(index);
                deleteMember = jangi.getMember(index)->getName();

                cout<< "Are you sure you want to remove "<< deleteMember << " from the Jangi system?"<<endl;
                cout<< "Enter y/n: ";
                cin>> response;

                if (member != 0) {

                if(response == "y" || response == "Y"){
                    jangi.removeMember(member);
                    delete member;
                    cout << deleteMember<< " has been removed from the Jangi system" << endl;


				}
				else if(response == "n" || response == "N"){
					cout<< "Delete Member Aborted"<<endl;
				}
			}

				else {
                    cout << "The Member does not exixts! Verify the Member Index and Try again" << endl;
                }

                break;
            }
               
            case 11:
                // Exit the program
                cout << "Exiting..." << endl;
                return 0;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

        cout << endl;
    }

    //return 0;
}
while(true);
}

