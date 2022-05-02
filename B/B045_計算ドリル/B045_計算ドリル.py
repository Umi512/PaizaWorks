# -*- coding: utf-8 -*-
import random

#while文の最大試行失敗数
LIMIT = 1000000

#入力値を取得する
setting = raw_input()
set_data = setting.split()

plus = int(set_data[0])
minus = int(set_data[1])

#足し算式リストを生成する
plus_res = []
count = 0
limit = 0

while count < plus:
    left = random.randint(0, 99)
    right = random.randint(0, 99 - left)

    temp = [left,"+",right,"="]

    if temp not in plus_res:
        plus_res.append(temp)
        count += 1
    else:
        limit += 1
        if limit >= LIMIT:
            print "足し算を総計",len(plus_res),"個生成しました．"
            print "試行回数を変更するには，LIMIT=",LIMIT,"を調整してください．"
            break

#引き算式リストを生成する
minus_res = []
count = 0
limit = 0

while count < minus:
    left = random.randint(0, 99)
    right = random.randint(0, left)

    temp = [left,"-",right,"="]

    if temp not in minus_res:
        minus_res.append(temp)
        count += 1
    else:
        limit += 1
        if limit >= LIMIT:
            print "引き算を総計",len(plus_res),"個生成しました．"
            print "試行回数を変更するには，LIMIT=",LIMIT,"を調整してください．"
            break

#出力順を決めるリストを生成する
array_res = []
count = 0
limit = 0

while count < (plus+minus):
    array = random.randint(0, len(plus_res) + len(minus_res) - 1)

    if array not in array_res:
        array_res.append(array)
        count += 1
    else:
        limit += 1
        if limit >= LIMIT * 2:
            print "計算式出力数を総計",len(plus_res),"個にしました．"
            print "試行回数を変更するには，LIMIT=",LIMIT,"を調整してください．"
            break

#作成式をまとめる
res = []
for i in plus_res:
    res.append(i)
for i in minus_res:
    res.append(i)

#結果を出力する
for i in array_res:
    print res[i][0],res[i][1],res[i][2],res[i][3]