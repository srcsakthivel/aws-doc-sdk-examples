﻿// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ComprehendSamples1
{
    class Program
    {
        static void Main(string[] args)
        {
            DetectDominantLanguage.Sample();
            DetectEntities.Sample();
            DetectKeyPhrases.Sample();
            DetectSentiment.Sample();
            TopicModeling.Sample();
            UsingBatchAPIs.Sample();
        }
    }
}
