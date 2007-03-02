require File.dirname(__FILE__) + '/../test_helper'

class SiComponentTest < Test::Unit::TestCase
  fixtures :si_components

  def setup
    @si_component = SiComponent.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiComponent,  @si_component
  end
end
