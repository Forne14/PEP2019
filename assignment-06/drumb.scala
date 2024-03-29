// Part 2 and 3 about a really dumb investment strategy
//======================================================


//two test portfolios

val blchip_portfolio = List("GOOG", "AAPL", "MSFT", "IBM", "FB", "AMZN", "BIDU")
val rstate_portfolio = List("PLD", "PSA", "AMT", "AIV", "AVB", "BXP", "CCI",
                            "DLR", "EQIX", "EQR", "ESS", "EXR", "FRT", "HCP")


// (1) The function below takes a stock symbol and a year as arguments.
//     It should read the corresponding CSV-file and reads the January
//     data from the given year. The data should be collected in a list of
//     strings for each line in the CSV-file.

import io.Source
import scala.util._

def get_january_data(symbol: String, year: Int) : List[String] = {
  val allData = Source.fromFile(symbol++ ".csv").getLines.toList
  val yearResults = allData.filter(i=>List(year.toString).exists(j=>i.startsWith(j)))
  yearResults
}



// (2) From the output of the get_january_data function, the next function
//     should extract the first line (if it exists) and the corresponding
//     first trading price in that year with type Option[Double]. If no line
//     is generated by get_january_data then the result is None; Some if
//     there is a price.


def get_first_price(symbol: String, year: Int) : Option[Double] = {

      val janData = get_january_data(symbol, year)
      if (janData.isEmpty){
        None
      }else{
      val firstResult = janData(0)
      val splitJanData = firstResult.split(",")
      val price = splitJanData(1)
      val x = price.toDouble
      Try(Some(x)).getOrElse(None)
    }
}



// (3) Complete the function below that obtains all first prices
//     for the stock symbols from a portfolio (list of strings) and
//     for the given range of years. The inner lists are for the
//     stock symbols and the outer list for the years.


def get_prices(portfolio: List[String], years: Range) : List[List[Option[Double]]] = {
  val firstPricesOfStocks =(
    for(year<-years)yield{
      for(company<-portfolio)yield{
            get_first_price(company,year)
          }
        }
      ).toList
       firstPricesOfStocks
     }




//==============================================
// Do not change anything below, unless you want
// to submit the file for the advanced part 3!
//==============================================


// (4) The function below calculates the change factor (delta) between
//     a price in year n and a price in year n + 1.

def get_delta(price_old: Option[Double], price_new: Option[Double]) : Option[Double] =(price_old, price_new) match {
  case (None, None) => None
  case (Some(d: Double), None) => None
  case (None, Some(d: Double))=> None
  case (Some(c: Double), Some(d: Double))=> Some((d-c)/c)
}



// (5) The next function calculates all change factors for all prices (from a
//     portfolio). The input to this function are the nested lists created by
//     get_prices above.

def get_deltas(data: List[List[Option[Double]]]) :  List[List[Option[Double]]] = {
  val outerLoopSizeList = {
    for (a<-data)yield
    a.length
  }
  val outerLoopSize = outerLoopSizeList(0) - 1

  val groupedCompany ={
    for(a<-(0 to outerLoopSize).toList)yield
    for(b<-data) yield
    b(a)
  }
  val rangeToGetDeltaList = {
    for (a<-groupedCompany) yield
    a.length
  }

  val rangeToGetDelta = rangeToGetDeltaList(0)-2

  val deltaVal = {
    for(a<-(0 to rangeToGetDelta).toList)yield
    for(b<-groupedCompany) yield
    get_delta(b(a), b(a+1))
  }
  deltaVal
}



// (6) Write a function that given change factors, a starting balance and an index,
//     calculates the yearly yield, i.e. new balance, according to our dumb investment
//     strategy. Index points to a year in the data list.

def yearly_yield(data: List[List[Option[Double]]], balance: Long, index: Int) : Long = {
  val resultsForYear = data(index).filter(_!=None)
  if (resultsForYear == Nil){
      balance
    }else if(index >= resultsForYear.length && index < 0){
      balance
    }else{
    val valToBeInvested = (balance/(resultsForYear.length).toDouble)
    val investmentValList = {
      for(b<-resultsForYear)yield
      b.get*valToBeInvested
    }
    val total = investmentValList.sum.toLong + balance
    total
  }
}


// (7) Write a function compound_yield that calculates the overall balance for a
//     range of years where in each year the yearly profit is compounded to the new
//     balances and then re-invested into our portfolio. For this use the function and
//     results generated under (6). The function investment calls compound_yield
//     with the appropriate deltas and the first index.

def compound_yield(data: List[List[Option[Double]]], balance: Long, index: Int) : Long = {
  if (index<data.length-1){
    compound_yield(data, yearly_yield(data,balance,index), index+1 )
  }
  else {
    yearly_yield(data,balance,index)
  }
}

def investment(portfolio: List[String], years: Range, start_balance: Long) : Long = {
  compound_yield(get_deltas(get_prices(portfolio, years)), start_balance, 0)
}




//Test cases for the two portfolios given above

//println("Real data: " + investment(rstate_portfolio, 1978 to 2018, 100))
//println("Blue data: " + investment(blchip_portfolio, 1978 to 2018, 100))
