require File.dirname(__FILE__) + '/../test_helper'

class SiResultTest < Test::Unit::TestCase
  fixtures :si_results

  def setup
    @si_result = SiResult.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiResult,  @si_result
  end
end
