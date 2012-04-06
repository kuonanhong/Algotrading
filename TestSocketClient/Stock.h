/*
 * Stock class
 */

#ifndef STOCK_H 
#define STOCK_H

#include "EMA.h"

#include<string>
#include<fstream>
#include<vector>
#include<map>

// Strategy idea: Exponential Ribbon

// Dummy stock class
class Stock{
    public:
        Stock(std::string tick);
		~Stock();
        EMA * getEMA(int id);
        MACD * getMACD(int id);
        double getCurEMA(int id);
        double getCurMACD(int id);
        double getPrice();
        std::string getTick();
		bool isShortable(){
			return shortable;
		}
		void newEMA(int num_periods, int id);
		void newMACD(int id);
		void updateShortable( double value);
		// see which ema and macd id it is and update it
		// and write to file
		void update(int id, double price);

	private:
	    std::string tick;

		// EMA and MACD objects (mapped by id)
		std::map<int, EMA*> EMAs;
		std::map<int, MACD*> MACDs;
		bool shortable;
		// Files for Price, EMA and MACD
		std::ofstream fPrice;
		std::map<int, std::ofstream*> fEMA;
		std::map<int, std::ofstream*> fMACD;
		
		// Most recent EMA, MACD and Price values
		std::map<int, double> curEMA;
		std::map<int, double> curMACD;
		double curPrice;
};

#endif
