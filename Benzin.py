from data import Data


class Benzin:
    """Стоимость разных видов бензина"""
    # магический метод init (заключается в том, чтобы инициализировать данные
    def __init__(self, vid, cost, data) -> None:
        self._vid, self._cost, self._data = vid, cost, Data(data)

    @property
    def vid(self):
        return self._vid

    @vid.setter
    def vid(self, value):
        self._vid = value

    @property
    def cost(self):
        return self._cost

    @cost.setter
    def cost(self, value):
        self._cost = value

    @property
    def data(self):
        return self._data

    @data.setter
    def data(self, value):
        self._data = value