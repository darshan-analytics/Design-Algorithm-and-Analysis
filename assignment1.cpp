#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include<sstream>
#include<map>
#include<string>
#include<math.h>
//#include<ctime>
#include<chrono>
//#include<time.h>
#include<iomanip>
using namespace std;
using namespace std::chrono;


typedef struct entercardinfo{

    string cardinfo;
    int price;
    int cardprice;
    string name;
   // entercardinfo();
    entercardinfo(string name, int price) : cardinfo(name), cardprice(price){}
    void setcard(string name){
    cardinfo = name;
    //cout << cardinfo << endl;
    }
    string getcardname(){
       // cout << "I am at get cardname" << endl;

        return cardinfo;
    }
    void setprice(int price)
    {
    cardprice = price;
    //cout<< cardprice << endl;
    }
    int getprice(){
      //  cout << "I am at getprice" << endl;
        return  cardprice;
    }


}entercardinfo;

pair<int, vector<entercardinfo>> ComputeMaxProfit(vector<entercardinfo> pricelist, int maxcost);
double getsum(vector<entercardinfo> item_set);
int get_profit(vector<entercardinfo> priceslists);
map<string, int> marketvalue;
vector<entercardinfo> subsets(vector<entercardinfo> vec, int set_size,
		int counter);

vector<entercardinfo> I;
map<string, int> market_price_list;
int W;
bool samefile;
ofstream outfile;
string market_price_name;
    pair<int, vector<entercardinfo>> HighestProfit = ComputeMaxProfit(I,W);
    
    bool checkforname(string hey)
    {
      if(market_price_list.find(hey) == market_price_list.end())
            {
                cout<< "wrong dataa"<< endl;

                return false;
            }
            else{
                return true;
            }  

    }






int main(int argc, char* argv[])
{ 
   // clock_t start_s , stop_s;
     
    
    int W;
    //string I;
    string name;
    //string market_price_name;
    int money;
    string pricelist;
    string mystring;
    string minestring;
    string numberofcards;
    string budget;
    int total_cards;
    int total_budget;
    int card_price;
    string price;
    //int numofMarketPrices = 0;
    int numberofcardsinmarketfile = 0;
    bool namechecking = false;
    //int temp[50];
    



    if (argc > 4) {
       // cout << "argv[1] = " << argv[1] << endl; 
       // cout << "argv[2] = " << argv[2] << endl;
    } else {
        cout << "No file name entered. Exiting...";
        return -1;
    }
    ifstream infile(argv[2]); //open the file
    
    
    if (infile.is_open() && infile.good()) {
        outfile.open("output.txt");
       // cout << "File is now open!\nContains:\n";
        string line = "";
        getline(infile, line);
        stringstream ss(line);
        getline(ss, minestring);
        numberofcardsinmarketfile = stoi(minestring);
       // cout<< numberofcardsinmarketfile <<endl;
      // int  counter = 1;


        while (getline(infile, line)){
            stringstream ss(line);

           // if(ss(line))
         
                        
            getline(ss, market_price_name, ' ');
            getline(ss, mystring);
            money = stoi(mystring);
           
            entercardinfo card (market_price_name, money);
            //map<string, int> market_price_list;
            market_price_list.insert(make_pair(market_price_name,money));
           //cout<< money << endl;
           // cout<< name << ": " <<  market_price_list[name] << endl;
    

            //marketvalue[name] = name;
           // marketvalue[price] = money;
            //maarketvalue[money] = money;
            //cout<<marketvalue[name]<< endl;
            //map<string, int> marketvalue;
           // marketvalue.insert(make_pair(name, money));
           /// cout << name <<endl;
            //cout << line << '\n';
        }
        
    } else {
        cout << "Failed to open file..";
    }    
    ifstream infile2(argv[4]); //open the file
     while(!infile2.eof())
     {
         
         I.clear();
     string word = "";
     
        
        getline(infile2, word);
        stringstream ss(word);

        getline(ss, numberofcards,' ');
        
        getline(ss, budget);
        total_budget = stoi(budget);
        W = total_budget;
      //  cout<< W << endl;
        total_cards = stoi(numberofcards);
       // cout<< total_cards << endl;
       

      
        
     for(int i =0 ; i < total_cards; i++){

      getline(infile2, word);

      stringstream ss(word);
      getline(ss, pricelist, ' ');
      getline(ss, price,' ');
      namechecking = checkforname(pricelist);
      card_price = stoi(price);
     // cout<<"BOOL" <<namechecking <<endl;
      if(namechecking == 0)
      {
          cout<< "no matching card has found in price list" << endl;
          return 1;
    
      }


     

      


     
   

   
      
      entercardinfo c (pricelist,card_price);
     // cout<<"Total cards" << total_cards << endl;

     





      
      I.push_back(c);
     

     

      //entercardinfo makingpair(name,card_price);
      //I.push_back(p);
     // cout<< card_price <<endl;
  
    
        }
       
       // cout<<"hhheeee" << I.size() << endl;
     auto start = steady_clock::now(); 
    // clock_t start_s = clock();
      

      
      pair<int, vector<entercardinfo>> HighestProfit = ComputeMaxProfit(I,W);


      
     /* //for(int m = 0; m< 50; m++)
      {
      //if(temp[m] == HighestProfit.first)
      {
          samefile = true;


      }
      else{
          //cout<< temp[m] <<endl;
          samefile = false;
      }
      }*/
      //outfile.open("output.txt");
     if(outfile.is_open())
      {
      
     if(samefile == false)
     {
      if(I.size()> 0)
      {


      //cout << "\nNo of cards: " << I.size() << endl;
      outfile << "\n"<< I.size();

      }
      
     
	 // cout << "Compute Max Profit: " << HighestProfit.first << endl;
      outfile <<"  " <<HighestProfit.first;
     // cout<< start_s << endl;

      

       
      
     auto stop = steady_clock::now(); 
      
   //   cout<<"heeeee"<<stop_s<< endl;
      auto duration = duration_cast<microseconds>(stop - start); 
      double time_here = duration.count();
      double tim = time_here/ 1000000;
      
  
      
     
	 vector<entercardinfo> max_card_set = HighestProfit.second;
     //cout<< "SECOND: " <<HighestProfit.second <<endl;
      
	  //cout << "No of possible card purchase: " << max_card_set.size() << endl;
      outfile  <<"  " <<max_card_set.size();
     //cout << "\nTime taken by function: " <<fixed <<tim<< setprecision(10)<< endl;
      outfile<<"  " <<fixed <<tim<< setprecision(10)<< endl;


	 // cout << "List of possible cards: " << endl;
     // outfile << "List of possible cards: " << endl;
      int count =0;

	  //for (int i = 0; i < max_card_set.size(); i++) 
      while(count < max_card_set.size()){
		//cout << max_card_set[count].getcardname() << "  ";
        outfile<<max_card_set[count].getcardname()<<endl;
        count++;


      }
     
     // cout<< "Tomeeeeee" << tim <<endl;
     // clock_t stop_s = clock();
     // double time_taken = (float(stop_s) - float(start_s)) / double(CLOCKS_PER_SEC)*1000;
     // double time = (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000;
  
     
       //cout<< "\nTime taken by function: "<<fixed<< duration.count() << setprecision(9)<<" seconds" << endl;
     // outfile << "\nTime taken by function: "<< duration.count() << " microseconds" << endl;
      

     }
           //outfile.close();

      }

      
     
      
       
        

       
    
   

   
    } 
    outfile.close();
    return 0;


}

pair<int, vector<entercardinfo>> ComputeMaxProfit(vector<entercardinfo> pricelist, int maxcost)
{
    int maxprofit = 0;
    vector<entercardinfo> current_set;
    vector<entercardinfo> max_profit;
    int cost = getsum(pricelist);
    if(cost <= maxcost)
    {
        //cout<< cost <<endl;
        maxprofit = get_profit(pricelist);
        max_profit = pricelist;
    }
    else{
        
        for(int counter= 0; counter< pow(2,pricelist.size()); counter++) { // set of n items will have 2^n subsets - counter for that

			current_set = subsets(pricelist, pricelist.size(), counter);

			double sum_of_weights = getsum(current_set); 

			//cout << "Sum of weights: " << sum_of_weights << endl;

			if (sum_of_weights <= maxcost) {
				double profit = get_profit(current_set);
				if (profit > maxprofit) {
					maxprofit = profit;
					max_profit = current_set;
				}
			}
			//counter++;
		}
	}
    std::pair<double, vector<entercardinfo>> best_profit = make_pair(maxprofit,
			max_profit);

	return best_profit;
}

int get_profit(vector<entercardinfo> marketvalues)
{
    

	

double total_profit = 0;
	for (vector<entercardinfo>::iterator it = marketvalues.begin();
			it != marketvalues.end(); ++it) {
               // cout << it ->getcardname() << ": " << "Market price : " << market_price_list[it ->getcardname()] << endl;
		total_profit = total_profit + (market_price_list[it ->getcardname()] - it->getprice());
	}
	//cout << "total profit: " << total_profit << endl;
	return total_profit;
}

double getsum(vector<entercardinfo> priceslists) {
	double cost = 0;
	for (vector<entercardinfo>::iterator it = priceslists.begin();
			it != priceslists.end(); ++it) {
		cost += it->getprice();
	}
	return cost;
}

vector<entercardinfo> subsets(vector<entercardinfo> vec, int set_size,
		int counter) {

	vector<entercardinfo> Vec;
    int j = 0;
    while(j< set_size)
    {
        if(counter & (1<<j)){
            Vec.push_back(vec[j]);
        }
        j = j+1;

    }
    return Vec;
	
}

    




    /*
    
    if (infile2.is_open() && infile2.good()) {
       // cout << "File is now open!\nContains:\n";
        string word = "";
        
        getline(infile2, word);
        stringstream ss(word);
        getline(ss, numberofcards,' ');
        
        getline(ss, budget);
        total_cards = stoi(numberofcards);
         //cout<<total_cards<<endl;
        while (getline(infile2, word)){
                          
                  string name, listedPrice;
                  //getline(infile2, word);
                  

                  istringstream ss(word);
                  getline(ss, name, ' ');
                 getline(ss, listedPrice);
                 int grannysPrice = stoi(listedPrice);
                 //cout << grannysPrice << '\n';
                 //break;
                 int arr[100];

                 for(int i= 0 ; i < total_cards; i++)
                 {
                     arr[i] = grannysPrice;
                     cout<< arr[0] << endl;
                     break;
                 }
            
        }
        
    } else {
        cout << "Failed to open file..";
    }

    return 0;
}
*/

