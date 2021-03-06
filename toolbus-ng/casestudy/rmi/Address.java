package casestudy.rmi;

import java.io.Serializable;

public class Address implements Serializable {
  private String zip;
  private String street;
  private int number;

  public void setZip(String zip) { this.zip = zip;}
  public String getZip() { return zip; }
  public void setStreet(String street) { this.street = street; }
  public String getStreet() { return street; }
  public void setNumber(int number) { this.number = number; }
  public int getNumber() { return number; }

  public boolean equals(Object o) {
    if (o instanceof Address) {
      Address peer = (Address) o;
      return peer.getStreet().equals(street) && peer.getNumber() == number;
    }
    return false;
  }

  public int hashCode() {
    return (street.hashCode() << 2) ^ number;
  }
}
