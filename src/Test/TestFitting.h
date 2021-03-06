#ifndef TEST_FITTING_H
#define TEST_FITTING_H

#include <QObject>

/// Unit test of Fitting classes
class TestFitting : public QObject
{
  Q_OBJECT
public:
  /// Single constructor.
  explicit TestFitting(QObject *parent = 0);

private slots:
  void cleanupTestCase ();
  void initTestCase ();

  // Test exact fit cases, for which the order equals the number of points minus 1
  void testFunctionExactFit01 ();
  void testFunctionExactFit12 ();
  void testFunctionExactFit23 ();
  void testFunctionExactFit34 ();

  // Test overfitted cases, for which the order is equal to, or greater than, the number of points
  void testFunctionOverfit11 ();
  void testFunctionOverfit22 ();
  void testFunctionOverfit33 ();
  void testFunctionOverfit44 ();

  // Test underfitted cases, for which the order is less than the number of points minus 1
  void testFunctionUnderfit02 ();
  void testFunctionUnderfit13 ();
  void testFunctionUnderfit24 ();
  void testFunctionUnderfit35 ();

  // Test case where non-function data was entered even though points should be functional
  void testNonFunction ();

  // Test the automatic order reduction as a function of the initial order
  void testOrderReduced3 ();
  void testOrderReduced4 ();
  void testOrderReduced5 ();
  void testOrderReduced6 ();

  // Test the automatic order reduction as a function of the significant digits
  void testSignificantDigits3 ();
  void testSignificantDigits4 ();
  void testSignificantDigits5 ();
  void testSignificantDigits6 ();  
  
 private:
  bool generalFunctionTest (int order,
                            int numPoints) const;
  bool generalNonFunctionTest () const;
  int orderReducedVersusOrderAndSignificantDigits (int order,
                                                   int significantDigits) const;
};

#endif // TEST_FITTING_H
