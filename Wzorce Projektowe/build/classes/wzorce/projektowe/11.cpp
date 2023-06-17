#include <iostream>

/**
 * Interfejs Product deklaruje operacje ktore wszystkie konkretne produkty
 * musza implementowac.
 */

class Product {
 public:
  virtual ~Product() {}
  virtual std::string Operation() const = 0;
};

/**
 * Konkretne produkty (ConcreteProduct) daja rozne implementacje interfejsu protuktu.
 */
class ConcreteProduct1 : public Product {
 public:
  std::string Operation() const override {
    return "{Wynik operacji ConcreteProduct1}";
  }
};
class ConcreteProduct2 : public Product {
 public:
  std::string Operation() const override {
    return "{Wynik operacji ConcreteProduct2}";
  }
};

/**
 * Klasa Creator deklaruje metode wytworcza ktora powinna zracac obiekt klasy
 * Product. Podklasy klasy Creator zazwyczaj daja implementacje tej metody.
 */

class Creator {
  /**
   * Pamietaj ze Creator moze tez posiadac domyslna implementacje metody wytworczej.
   */
 public:
  virtual ~Creator(){};
  virtual Product* FactoryMethod() const = 0;
  /**
   * Pamietaj takze, ze pomimo swej nazwy, glownym obowiazkiem klasy Creator
   * nie jest tworzenie produktow. Zazwyczaj zawiera ona glowna logike ktora
   * opiera sie na obiektach Product, zawracanych przez metode wytworcza.
   * Podklasy moga niebezposrednio zmieniac ta logike nadpisujac metode wytworcza
   * i zwracac inny typ produktu.
   */

  std::string SomeOperation() const {
    // Wywolaj metode wytworcza aby utworzyla obiekt Product.
    Product* product = this->FactoryMethod();
    // A teraz uzywamy produktu.
    std::string result = "Creator: Ten sam kod kreatora pracowa³ z " + product->Operation();
    delete product;
    return result;
  }
};

/**
 * Konkretne kreatory (ConcreteCreators) nadpisuja metode wytworcza w celu
 * zmiany typu tworzonego produktu.
 */
class ConcreteCreator1 : public Creator {
  /**
   * Zauwaz, ze sygnatura metody nadal uzywa abstrakcyjnego typu produktu,
   * nawet jesli konkretny produkt jest faktycznie zwracany z metody. W ten
   * sposob klasa Creator moze pozostaæ niezale¿na od klas konkretnych produktow.
   */
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator {
 public:
  Product* FactoryMethod() const override {
    return new ConcreteProduct2();
  }
};

/**
 * Kod klienta dziala z instancja konkretnego kreatora, aczkolwiek poprzez
 * jego podstawowy interfejs. Tak dlugo, jak klient kontynuuje wspolpracê z kreatorem
 * za posrednictwem podstawowego interfejsu, mozesz przekazac go dowolnej podklasie
 * kreatora.
 */
void ClientCode(const Creator& creator) {
  // ...
  std::cout << "Client: Nie jestem swiadomy klasy Kreator, ale operacja jest wykonywana.\n"
            << creator.SomeOperation() << std::endl;
  // ...
}

/**
 * Aplikacja wybiera typ kreatora w zaleznosci od konfiguracji lub srodowiska.
 */

int main() {
  std::cout << "Metoda wytworcza:\n\n";
  std::cout << "App: Uruchamiam z ConcreteCreator1.\n";
  Creator* creator = new ConcreteCreator1();
  ClientCode(*creator);
  std::cout << std::endl;
  std::cout << "App: Uruchamiam z ConcreteCreator2.\n";
  Creator* creator2 = new ConcreteCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}
