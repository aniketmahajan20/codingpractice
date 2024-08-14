from collections import deque
import re
class BasicCalculator:
    def __init__(self) -> None:
        self.precedence = {
            "+": 2,
            "-": 1,
            "*": 3,
            "/": 4,
            " ": 0
        }
        self.stack = deque()
        self.result = 0
        pass

    def evaluate(self, operandA, operandB, operator):
        if self.precedence[operator] == 1:
            return  operandB - operandA
        if self.precedence[operator] == 2:
            return  operandB + operandA
        if self.precedence[operator] == 3:
            return  operandB * operandA
        if self.precedence[operator] == 4:
            return  operandB / operandA
        
    def create_stack(self, s: str):
        operands_operators = re.split("([-()+*/])", s)
        for element in operands_operators:
            if element in self.precedence:
                element.strip()
                self.stack.append(element)  
            else:
                element.strip()
                self.stack.append(float(element))  
    
    def calculate_expression(self, s: str):
        self.create_stack(s)
        while(len(self.stack) != 1):
            try:
                operandA = self.stack.pop()
                assert isinstance(operandA, float)
                operatorA = self.stack.pop()
                assert isinstance(operatorA, str)
                operandB = self.stack.pop()
                assert isinstance(operandB, float)
                if (len(self.stack) > 1):
                    operatorB = self.stack.pop()
                    assert isinstance(operatorB, str)
                    if (self.precedence[operatorA] < self.precedence[operatorB]):
                        operandC = self.stack.pop()
                        self.result = self.evaluate(operandB, operandC, operatorB)
                        self.stack.append(self.result)
                        self.stack.append(operatorA)
                        self.stack.append(operandA)
                        continue
                self.result = self.evaluate(operandA, operandB, operatorA)
                if (len(self.stack) >= 1):
                    self.stack.append(operatorB)
                self.stack.append(self.result)
            except:
                return 12345
        return self.result
        
if __name__ == "__main__":
    a = BasicCalculator()
    print(a.calculate_expression("1+2/3*3 + 4*55"))