# Algorithmic Trading Application

### Description of Project 
As a research project for Financial IT, the team decided on creating an algorithmic trading application. The algorithmic trading application is designed to receive real time and historical market data. The application will generate buy and sell signals based on technical analysis. The application will also carry out trading by submitting orders based on the technical analysis indicator signals. The Interactive Brokers API will serve as the main interface for the retrieval of real-time and historical market data as well as for submitting orders. In order to minimize any technical issues with transferring files the team unanimously decided the best option was to solely use the 2013 version of Microsoft Visual Studio. 

### Description of Models 
The technical indicators used in this application were the MACD, Fast Stochastics, Chaikin Money Flow, and VWAP. The formulas where modeled after the information available at StockCharts: http://stockcharts.com/school/doku.php?id=chart_school/

#### MACD
The MACD Line is the 12-day Exponential Moving Average(EMA) less the 26-day EMA. Closing prices are used for these moving averages. A 9-day EMA of the MACD Line is plotted with the indicator to act as a signal line and identify turns. 
MACD Line: (12-day EMA - 26-day EMA)
Signal Line: 9-day EMA of MACD Line

A buy signal occurs when the MACD line crosses above the Signal line.

#### FAST STOCHASTICS
Stochastics consists of 2 parameters which are %K and %D. The value of %K is ranging from 0 to 100 depends on how high is the recent closing price with respect to the highest and lowest price attained during the specified period. %D is obtained by taking a moving average of %K.

We used 14 periods, with 1 period = 1 day.

#### VWAP

The Volume Weighted Average Price was calculated using the built-in function in the TWS API using the most recent historical data. If the current price is lower than the VWAP, we generate a “Buy” signal.

##User Guide

When you start the application, click the “Connect” button to connect to the TWS servers.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/1.png)

Next, select the ticker symbol of the company you want, and press “Go” to prepare the application for use.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/2.png)

After pressing “Go” you will see the ticker symbol show up in blue. This means you are ready to start streaming data. Press the “Start” button to begin data retrieval.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/3.png)

You should see the data start to populate the charts, and the indicators sections.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/4.png)

Notice the real-time data will begin to populate with a candlestick chart. The price is the blue series, the volume is in the secondary chart area in yellow. 

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/5.png)

You can also see the historical data for the last 26 days, displayed in the following chart with the Price, the Exponential Moving Average for 26 days and 12 days, and the Volume in the secondary chart area on the bottom.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/6.png)

The indicators will begin to update. Once the programmed signals are all in the green, in this case the CMF20, Signal(9), and %D(14,3), an automated limit buy order of 100 shares at the current price will be placed.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/7.png)

You will see order information come up in the order table.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/8.png)

You will also see an order complete message from TWS when the order is filled.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/9.png)

You can check your TWS application and confirm that the orders have been placed.

![myimage-alt-tag](https://github.com/akmay/algorithmic-trading/blob/master/10.png)
