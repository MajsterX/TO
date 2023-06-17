#include <iostream>

/**
 * Kazdy odrebny produkt z rodziny produktow powinien miec interfejs
 * podstawowy. Wszystkie warianty produktu musza implementowac ten interfejs.
 */
class AbstractProductA {
 public:
  virtual ~AbstractProductA(){};
  virtual std::string UsefulFunctionA() const = 0;
};

/**
 * Konkretne Produkty sa tworzone przez odpowiednie Konkretne Fabryki.
 */
class ConcreteProductA1 : public AbstractProductA {
 public:
  std::string UsefulFunctionA() const override {
    return "Wynik produktu A1.";
  }
};

class ConcreteProductA2 : public AbstractProductA {
  std::string UsefulFunctionA() const override {
    return "Wynik produktu A2.";
  }
};

/**
 * Oto podstawowy interfejs innego produktu. Wszystkie produkty moga wchodziæ
 * w interakcje ze soba, ale wlasciwa interakcja jest mozliwa tylko mirdzy
 * produktami tego samego konkretnego wariantu.
 */
class AbstractProductB {
  /**
   * ProductB moze robic swoje...
   */
 public:
  virtual ~AbstractProductB(){};
  virtual std::string UsefulFunctionB() const = 0;
  /**
   * ... ale moze równiez wspolpracowac z ProductA.
   *
   * Fabryka Abstrakcyjna dba o to, aby wszystkie tworzone przez nia produkty
   * mialy ten sam wariant, a zatem byly kompatybilne.
   */
  virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

/**
 * Konkretne Produkty sa tworzone przez odpowiednie Konkretne Fabryki.
 */
class ConcreteProductB1 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override {
    return "Wynik produktu B1.";
  }
  /**
   * Wariant (ProduktB1) może prawidlowo pracowac jedynie z wariantem ProduktA1.
   * Mimo wszytko zaakcceptuje dowolna instancje klasy AbstractProductA jako
   * argument.
   */
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "Wynik produktu B1 we wspolpracy z ( " + result + " )";
  }
};

class ConcreteProductB2 : public AbstractProductB {
 public:
  std::string UsefulFunctionB() const override {
    return "Wynik produktu B2.";
  }
  /**
   * Wariant (Product B2) może prawidlowo pracowac jedynie z wariantem ProduktA2.
   * Mimo wszytko zaakcceptuje dowolna instancje klasy AbstractProductA jako
   * argument.
   */
  std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "Wynik produktu B2 we wspolpracy z ( " + result + " )";
  }
};

/**
 * Interfejs Fabryki abstrakcyjnej deklaruje zestaw metod, ktore zwracaja rozne
 * produkty abstrakcyjne. Produkty te nazywane sa rodziną i sa powiazane tematem
 * lub koncepcja wysokiego poziomu. Produkty z jednej rodziny zazwyczaj moga ze
 * soba wspolpracowac. Rodzina produktow moze miec kilka wariantow, ale produkty
 * jednego wariantu są niekompatybilne z produktami innego.
 */
class AbstractFactory {
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};

/**
 * Konkretne Fabryki wytwarzaja rodzine produktow nalezących do jednego wariantu.
 * Fabryka gwarantuje kompatybilność powstałych produktow. Zauwaz, ze sygnatury
 * metod Konkretnej Fabryki zwracaja produkt abstrakcyjny, podczas gdy wewnątrz
 * metody tworzony jest konkretny produkt.
 */
class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
  }
};

/**
 * Kazda Konkretna Fabryka ma odpowiadajacy wariant produktu.
 */
class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB2();
  }
};

/**
 * Kod kliencki wspołpracuje z fabrykami i produktami tylko za posrednictwem typow
 * abstrakcyjnych: AbstractFactory i AbstractProduct. Pozwala to przekazac dowolna
 * podklase fabryki lub produktu do kodu klienta bez lamania go.
 */

void ClientCode(const AbstractFactory &factory) {
  const AbstractProductA *product_a = factory.CreateProductA();
  const AbstractProductB *product_b = factory.CreateProductB();
  std::cout << product_b->UsefulFunctionB() << "\n";
  std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
  delete product_a;
  delete product_b;
}

int main() {
  std::cout << "Fabryka abstrakcyjna:\n\n";
  std::cout << "Client: Testowanie Kocu klienckiego z pierwszym typem fabryki:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testowanie Kocu klienckiego z drugim typem fabryki:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}
