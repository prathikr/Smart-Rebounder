class lowpassfilter:

    def __init__(self, RC):
        self.RC = RC
        self.oldValue = 500
        self.currentValue = 500

    def update(self, value, dt):
        self.oldValue = self.currentValue
        alpha = dt / (self.RC + dt)
        self.currentValue = alpha * value + (1 - alpha) * self.oldValue
        return self.currentValue
    
    def getCurrentValue(self):
        return self.currentValue