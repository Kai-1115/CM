# pip install requests
# pip install beautifulsoup4
import datetime
import requests
from bs4 import BeautifulSoup
import numpy as np
import matplotlib.pyplot as plt
import base64
from io import BytesIO

# 取得前一個月的時間
date = datetime.date.today()
str_date = str(date.replace(month=date.month-1))
list_date = []
for i in range(len(str_date)): 
    if (i != 4)&(i != 7): 
        list_date.append(str_date[i])
string_space = ""
date = string_space.join(list_date)

# 爬蟲前一個月的數據（台灣證券交易所）
stock_num = input("請輸入股票代號: ")
response = requests.get("""https://www.twse.com.tw/rwd/zh/afterTrading/STOCK_DAY?date=%s
                            &stockNo=%s&response=html""" % (date,stock_num)) 
soup = BeautifulSoup(response.text, "html.parser")
results = soup.find_all("td")
result_list = [] 
for result in results:
    text_content = result.get_text()
    result_list.append(text_content)

# 取得今天的時間
date = datetime.date.today()
str_date = str(date)
list_date = []
for i in range(len(str_date)): 
    if (i != 4)&(i != 7): 
        list_date.append(str_date[i])
string_space = ""
date = string_space.join(list_date)

# 爬蟲這一個月的數據（台灣證券交易所）
response = requests.get("""https://www.twse.com.tw/rwd/zh/afterTrading/STOCK_DAY?
                        date=%s&stockNo=%s&response=html""" % (date,stock_num))
soup = BeautifulSoup(response.text, "html.parser")
results = soup.find_all("td")
for result in results:
    text_content = result.get_text()
    result_list.append(text_content)

# 整理所需數據 日期 成交股數 成交金額 開盤價 V最高價 V最低價 V收盤價 漲跌價差 成交筆數
high_list = []
low_list = []
closing_list = []
for i in range(len(result_list)):
    if i % 9 == 4:
        high_list.append(result_list[i])
    if i % 9 == 5:
        low_list.append(result_list[i])
    if i % 9 == 6:
        closing_list.append(result_list[i])

# 計算近幾日的RSV、K、D值
k_list = [50]
d_list = [50]
for i in range(len(high_list)-9):
    closing = float(closing_list[len(closing_list)-1])
    lowest = float(min(*low_list[i:i+10]))
    highest = float(max(*high_list[i:i+10]))
    
    rsv = (closing - lowest) / (highest - lowest) * 100
    k = 1/3 * rsv + 2/3 * d_list[i]
    d = 1/3 * k + 2/3 * k_list[i]
    k_list.append(k)
    d_list.append(d)

fig, ax = plt.subplots()
x = np.arange(1,len(high_list)-8)
ax.plot(x, k_list[1:],color="darkblue",label="Kill")
ax.plot(x, d_list[1:],color="darkorange",label="Death")
ax.set_xlabel("Date")
ax.set_ylabel("Value")
ax.set_title("%s K/D Line Chart"%(stock_num))
ax.legend()

# 把圖表轉成64進位 (壓縮資料 => 方便導入網頁)
tmpfile = BytesIO()
fig.savefig(tmpfile, format='png')
encoded = base64.b64encode(tmpfile.getvalue()).decode('utf-8')

# 技術面分析1
# D線判斷市場行情
if d_list[-1] >= 80:
    judge_d = "超買訊號、市場過熱，隨時可能回檔或下跌，但還要注意反轉，建議等出現死亡交叉後再賣出"
elif d_list[-1] > 50:
    judge_d = "投資者對股市看好，預計股價將會看漲"
elif d_list[-1] == 50:
    judge_d = "投資者對股市看法一半一半，股價呈現小幅度波動"
elif d_list[-1] > 20:
    judge_d = "投資者對股市看衰，預計股價將會看跌"
elif d_list[-1] <= 20:
    judge_d = "超賣訊號、市場過冷，隨時可能反彈或回升，但需考慮鈍化問題，建議等出現黃金交叉後再買進"

# 技術面分析2
# 判斷黃金、死亡交叉
cross = ""
if k_list[-1] > d_list[-1]:
    for i in range(-2,-5,-1):
        if k_list[i] < d_list[i]:
            cross = "K、D線黃金交叉,建議買進做多"

if d_list[-1] > k_list[-1]:
    for i in range(-2,-5,-1):
        if k_list[i] > d_list[i]:
            cross = "K、D線死亡交叉,建議賣出做空"

# 建立html檔案
html = '<html>' 
html += '<title>Stock %s Analyze</title>'%(stock_num)
html += '<h2>股票代碼： %s</h2>'%(stock_num)
html += '<p>最近一天的K值: %d 最近一天的D值: %d</p>'%(k_list[-1],d_list[-1])
html += "<h3>技術面分析結果: </h3>"
html += '<p>%s</p>'%(judge_d)
if cross == "":
    html += "<p>近三天沒有發生K、D線交叉的情況</p>"
else:
    html += "<p>%s</p>"%(cross)
html += "<h3>%sK、D線圖表如下: </h3>"%(stock_num)
html += '<img src=\'data:image/png;base64,{}\'>'.format(encoded) 
html += '</html>'

with open('KD Chart.html','w') as f:
    f.write(html)