from Benzin import Benzin


def red_file() -> list:
    with open("txt.txt") as f: #считываем файл
        info = list()
        while True:
            vid = f.readline()
            if vid == "":
                break
            else:
                vid = vid[:-1]
            cost = f.readline()[:-1]
            data = f.readline()
            if data[-1] == "\n":
                data = data[:-1]
            info.append(Benzin(vid, cost, data))
    return info


def information(mas: list):
    for i in mas:
        print(f"Вид бензина {i.vid} стоит {i.cost} рублей на {i.data}")


information(red_file())