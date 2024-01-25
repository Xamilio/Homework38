#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;
class QueueRing
{
	//Очередь
	int* Wait;
	//Максимальный размер очереди
	int MaxQueueLength;
	//Текущий размер очереди
	int QueueLength;
public:
	//Конструктор
	QueueRing(int m);
	//Деструктор
	~QueueRing();
	//Добавление элемента
	void Add(int c);
	//Извлечение элемента
	int Extract();
	//Очистка очереди
	void Clear();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	//демонстрация очереди
	void Show();
};
void QueueRing::Show() {
	cout << "\n-----------------------------------\n";
	//демонстрация очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-------------------------------------\n";
}
QueueRing::~QueueRing()
{
	//удаление очереди
	delete[]Wait;
}
QueueRing::QueueRing(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//Изначально очередь пуста
	QueueLength = 0;
}
void QueueRing::Clear()
{
	//Эффективная "очистка" очереди
	QueueLength = 0;
}
bool QueueRing::IsEmpty()
{
	//Пуст?
	return QueueLength == 0;
}
bool QueueRing::IsFull()
{
	// Полон?
	return QueueLength == MaxQueueLength;
}
int QueueRing::GetCount()
{
	//Количество присутствующих в стеке элементов 
	return QueueLength;
}
void QueueRing::Add(int c)
{
	//Если в очереди есть свободное место, 
	//то увеличиваем количество
	//значений и вставляем новый элемент 
	if (!IsFull())
		Wait[QueueLength++] = c;
}
int QueueRing::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь 
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//забрасываем первый "вытолкнутый элемент
		//в конец"
		Wait[QueueLength - 1] = temp;
		return temp;
	}
	else return 0;
}
void play(QueueRing& slot) {
	int coins = 20;
	while (true)
	{
		int sl1 = rand() % 100 + 1;
		int sl2 = rand() % 100 + 1;
		int sl3 = rand() % 100 + 1;
		int s1 = 0;
		int s2 = 0;
		int s3 = 0;
		char key[230];
		for (int i = 0; i < sl1; i++)
			s1 = slot.Extract();

		for (int i = 0; i < sl2; i++)
			s2 = slot.Extract();

		for (int i = 0; i < sl3; i++)
			s3 = slot.Extract();

		cout << s1 << " " << s2 << " " << s3 << "\n";
		if (s1 == s2 && s2 == s3)
		{
			coins = coins + 4;
			cout << "Вы выиграли! Ваш выигрыш 4, на счету: " << coins << "\n";
		}
		else
		{ 
			coins = coins - 1;
			cout << "Вы проиграли! Ваш проигрыш 1, на счету: " << coins << "\n";
		}
		if (coins == 0)
		{
			cout << "Будут деньги приходите еще!\n";
			return;
		}
		cout << "Продолжение Y или любой символ для выхода: ";
		cin >> key;
		if (key[0] != 'Y' && key[0] != 'y') return;
	}
}
int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	QueueRing slot(4);
	for (int i = 0; i < 4; i++)
		slot.Add(i);
	slot.Show();
	play(slot);
	
}


