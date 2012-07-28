require File.dirname(__FILE__) + '/../test_helper'

class SiProfileTest < Test::Unit::TestCase
  fixtures :si_profiles

  def setup
    @si_profile = SiProfile.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiProfile,  @si_profile
  end
end
