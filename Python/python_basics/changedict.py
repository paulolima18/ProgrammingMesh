def upsidown(recipe):
# cake needs x elements, this function gives: elements are used in x cakes
    for key, value in recipe.items():
      for elem in value:
        if elem not in dicio:
          dicio[elem] = [key]
        else:
          dicio[elem].append(key)
    return dicio

def checker(dicio):
    #checks max number of elements in "cake"
    key_num = 0 # max value of keys
    for k in dicio:
      key_length = len(dicio[k])
      if key_length >= key_num:
        key_num = key_length
    return key_num

def result(dicio,keys):
    final_dict = {}
    for k in dicio:
      if len(dicio[k]) == keys:
        final_dict[k] = dicio[k]
    return final_dict

if __name__ == "__main__":

    recipe = {'dreams':['flour', 'egg', 'sugar'],
    'french toast':['bread', 'sugar', 'egg'],
    'cake':['water', 'milk','sugar', 'egg']}

    dicio = {}
    final_res = {}
    key_num = 0

    dicio = upsidown(recipe)
    print(dicio)

    key_num = checker(dicio)
    print(key_num)

    final_dict = result(dicio,key_num)
    print(final_dict)

""" This Program receives a dictionary (key/values) and returns a dictionary
    with only the values that showed up in all keys,followed up by the
    specefied keys
"""
