import requests

def getCurrencies():
    myList = requests.get('https://api.uphold.com/v0/ticker/').json()

    currencyList = []

    seen = set(currencyList)

    for eachDict in myList:
        for currency in eachDict.keys():
            if (currency == 'currency'):
                if eachDict[currency] not in seen:
                    seen.add(eachDict[currency])
                    currencyList.append(eachDict[currency])

    return currencyList

def curl(startCurrency,currency):
    http = 'https://api.uphold.com/v0/ticker/'
    http = http + startCurrency + currency
    r = requests.get(http)

    """if (r.json().get('code') == None):
        print('\n'+ startCurrency +' to ' + currency + ' conversion')
        print('Smallest price being asked by the market: '+r.json()['ask'])
        print('Highest price being bought in the market: '+r.json()['bid']+'\n')
    else:
        print("\nPlace a valid currency!\n")"""
    return r.json()

def loop(choosen_currency,startCurrency,currencyList):

    """for currency1 in currencyList:
        for currency2 in currencyList:
            string = 'https://api.uphold.com/v0/ticker/'
            string = string + currency1 + currency2
            curl(string,currency1)"""
    value = [0]
    minimum = 0
    for currency in currencyList:
        if currency != choosen_currency[0] and currency != startCurrency:
            x = curl(choosen_currency[0],currency)['bid']
            #print('x = %f'%float(x) +'\n' + '%f*x = %f'%(choosen_currency[1],choosen_currency[1]*float(x)))
            x = choosen_currency[1]*float(x)
            #print("Currency: "+currency)
            #print("Start Currency: "+startCurrency)
            #print("Choosen Currency: "+choosen_currency[0])
            middle = float(curl(currency,startCurrency)['bid']) * x
            #print("middle:%f"%middle)
            if (middle > minimum):
                print('ok middle:%f minimum: %f'%(middle,minimum))
                minimum = middle
                value = [minimum,currency]

    return value

# Possible pay made by switching currency 3 times (tax not counted)
## startCurrency (BTC) | currency_1 (USD) | iterator (EUR) | startCurrency (BTC)
# X | Y | Z | X
def main():
    currencyList = getCurrencies() #Get all of the currencies currently available

    for startCurrency in currencyList: #Starts iteration | X
        for currency in currencyList: #Chooses first transformation | Y
            if (startCurrency != currency):
                #print(startCurrency+"normal"+currency)
                initial_value = float(curl(startCurrency,currency)['bid']) #Amount of Y given by 1 X
                #print("value: %f"%initial_value)
                choosen_currency = [currency,initial_value] #list [Y,amount_Y]
                end_value = loop(choosen_currency,startCurrency,currencyList) #Y to Z to X

                if end_value[0] > 1:
                    print("Start: 1")
                    print("End: %f"%end_value[0])
                    print(startCurrency+" to "+currency+" to "+end_value[1]+" to "+startCurrency)
                    return 1


if __name__=='__main__':
    main()
    print('Bye')
