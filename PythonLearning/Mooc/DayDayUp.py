#!/usr/bin/env python3

#Q1
dayup = pow(1.001, 365)

daydown = pow(0.999, 365)

print("向上:{:.2f}".format(dayup), "向下:{:.2f}".format(daydown))

#daydayupQ2
dayFactor = 0.01
dayup = pow(1+dayFactor, 365)
daydown = pow(1-dayFactor, 365)
print("向上:{:.2f}".format(dayup), "向下:{:.2f}".format(daydown))

#daydayupQ3
'''工作日努力，工作日进步百分之一，周末退步百分之一'''
dayup = 1.0
workDayFactor = 0.01
weekDayFactor = -0.01
for i in range(365):
    if i % 7 in [6,0]:
        dayup *=  (1 + weekDayFactor)
    else:
        dayup *= (1 + workDayFactor)
print("工作日的力量为：{:.2f}".format(dayup))

#daydayupQ4
def dayup(dayfactor):
    dayup = 1.0
    for i in range(365):
        if i % 7 in [6, 0]:
            dayup *= (1 - 0.01)
        else:
            dayup *= (1 + dayFactor)
    return dayup

dayFactor = 0.01
while dayup(dayFactor) < 37.78:
    dayFactor += 0.001
print("工作日的努力因数为：{:.3f}".format(dayFactor))
