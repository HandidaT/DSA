import pandas as pd
import numpy as np
from pprint import pprint

#import the dataset
dataset = pd.read_csv("/home/han/Desktop/dnet/compsci/6ml/ML_A-Z/Part_3_Classification/Section_19_Decision_Tree_Classification/Python/zoo.csv", names=['animal_name','hair','feathers','eggs',
                                      'milk','airborne','aquatic','predator','toothed',
                                       'backbone','breathes','venomous',
                                       'fins','legs','tail',
                                       'domestic','catsize','class_type'],header=0)
#we drop this feature,since this is not good feature to split the data
dataset = dataset.drop('animal_name',axis=1)
print(dataset,"\n\n==",dataset.columns)
print(dataset["class_type"])
###defining entropy
def entropy(target_col):
    elements,counts = np.unique(target_col,return_counts=True)
    entropy = np.sum([(-counts[i]/np.sum(counts))*np.log2(counts[i]/np.sum(counts)) for i in range(len(elements))])
    print("Entropy ",elements,counts,entropy,len(elements))
    return entropy

entropy(dataset["class_type"])
print("first entropy")

##Info Gain

def InfoGain(data,split_attribute_name,target_name="class_type"):
    total_entropy = entropy(data[target_name])
    vals,counts = np.unique(data[split_attribute_name],return_counts=True)
    #cal the weighted entropy
    print("IIIIIIIIIIIIIIIIIIIIIInfoGain len(vals)=",len(vals))
    Weighted_Entropy = np.sum([(counts[i]/np.sum(counts))*entropy(data.where(data[split_attribute_name]==vals[i]).
                                dropna()[target_name])for i in range(len(vals))])
    
    #formula for information gain
    Information_Gain = total_entropy-Weighted_Entropy
    print("InfoGain after", total_entropy, Weighted_Entropy, Information_Gain)
    return Information_Gain

glob=0
def ID3(data,originaldata,features,target_attribute_name="class_type",
        parent_node_class=None):
    global glob
    glob+=1
    print("glob ",glob)
    #If all target_values have the same value,return this value
    if len(np.unique(data[target_attribute_name])) <= 1:
        glob-=1
        print("--1 glob",glob,np.unique(data[target_attribute_name]))
        return np.unique(data[target_attribute_name])[0]
    
    #if the dataset is empty
    elif len(data) == 0:
        glob-=1
        print("--2 glob",glob)
        return np.unique(originaldata[target_attribute_name])[np.argmax(np.unique(originaldata[target_attribute_name],
                                                                           return_counts=True)[1])]
    
    #If the feature space is empty
    elif len(features) == 0:
        glob-=1
        print("--3 glob",glob)
        return parent_node_class 

    #If none of the above condition holds true grow the tree

    else:
        print("--4-----------infogain will be called",len(features),"times(no of features)")
        parent_node_class = np.unique(data[target_attribute_name])[np.argmax(np.unique(data[target_attribute_name],
                                                                           return_counts=True)[1])]

    #Select the feature which best splits the dataset
    item_values = [InfoGain(data,feature,target_attribute_name)for feature in features] #Return the infgain values
    best_feature_index = np.argmax(item_values)
    print("item_values ",item_values,best_feature_index,"how can it be argmax")
    best_feature = features[best_feature_index]

    #Create the tree structure
    tree = {best_feature:{}}

    #Remve the feature with the best info gain
    features = [i for i in features if i!= best_feature]

    #Grow the tree branch under the root node
    print(best_feature,np.unique(data[best_feature]),"parent_node_class",[(np.unique(data[target_attribute_name],
                                                                           return_counts=True)[1])])
    for value in np.unique(data[best_feature]):
        value = value
        sub_data = data.where(data[best_feature]==value).dropna()
        print("---------------------",value,target_attribute_name,parent_node_class,"\n", sub_data)
        #call the ID3 algotirthm
        subtree = ID3(sub_data,dataset,features,target_attribute_name,parent_node_class)
        #Add the subtree
        print("----------------------------------------------subtree",subtree)
        print("for value ",value)
        tree[best_feature][value] = subtree
        print(subtree)
        pprint(tree)
    glob-=1
    print("--5 glob", glob)
    return(tree)

#Predict
def predict(query,tree,default=1):
    for key in list(query.keys()):
        if key in list(tree.keys()):
            try:
               result = tree[key][query[key]]
            except:
               return default

            result = tree[key][query[key]]
            if isinstance(result,dict):
                return predict(query,result)
            else:
                return result
##check the accuracy

def train_test_split(dataset):
    training_data = dataset.iloc[:80].reset_index(drop=True)
    testing_data = dataset.iloc[80:].reset_index(drop=True)
    return training_data,testing_data
training_data = train_test_split(dataset)[0]
testing_data = train_test_split(dataset)[1]

def test(data,tree):
   queries = data.iloc[:,:-1].to_dict(orient="records")
   print(queries)
   predicted = pd.DataFrame(columns=["predicted"])

   #calculation of accuracy

   for i in range(len(data)):
       predicted.loc[i,"predicted"] = predict(queries[i],tree,1.0)
   print("predicted",predicted)
   print(data["class_type"])
   print("The Prediction accuracy is:",(np.sum(predicted["predicted"]==data["class_type"])/len(data))*100,'%')
  
print("training_data\n",training_data)
print("training_datacoulumns\n",training_data.columns[:-1])
#Train the tree,print the tree abnd predict the accuracy
tree = ID3(training_data,training_data,training_data.columns[:-1])
pprint(tree)
test(testing_data,tree)

