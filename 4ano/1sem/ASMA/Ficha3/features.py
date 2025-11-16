class Location:
    """Classe para representar coordenadas GPS"""
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __str__(self):
        return f"({self.x:.2f}, {self.y:.2f})"

def random_location(x_range=(0, 100), y_range=(0, 100)):
    """Gera uma localização aleatória dentro dos intervalos fornecidos"""
    x = random.uniform(*x_range)
    y = random.uniform(*y_range)
    return Location(x, y)

def calculate_distance(loc1, loc2):
    """Calcula distância Euclidiana entre dois pontos"""
    return math.sqrt((loc2.x - loc1.x)**2 + (loc2.y - loc1.y)**2)
