package casestudy.rmi;

import java.io.Serializable;

public class Address implements Serializable {
  private String street;
  private String number;

  public Address(String street, String number) {
    this.street = street;
    this.number = number;
  }

  public String getStreet() {
    return street;
  }
  
  public String getNumber() {
    return number;
  }

  public boolean equals(Object o) {
    if (o instanceof Address) {
      Address peer = (Address) o;
      return peer.getStreet().equals(street) && peer.getNumber().equals(number);
    }
    return false;
  }

  public int hashCode() {
    return (street.hashCode() << 2) ^ number.hashCode();
  }
}
