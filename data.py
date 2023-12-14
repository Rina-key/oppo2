class Data:
    """Дата"""
    def __init__(self, data: str) -> None:
        mas_data = data.split("-")
        self._day = mas_data[0]
        self._month = mas_data[1]
        self._year = mas_data[2]

    def __str__(self) -> str:
        return f"{self.day}.{self.mouth}.{self.year}"

    @property
    def day(self):
        return self._day

    @day.setter
    def day(self, value):
        self._day = value

    @property
    def mouth(self):
        return self._month

    @mouth.setter
    def mouth(self, value):
        self._month = value

    @property
    def year(self):
        return self._year

    @year.setter
    def year(self, value):
        self._year = value